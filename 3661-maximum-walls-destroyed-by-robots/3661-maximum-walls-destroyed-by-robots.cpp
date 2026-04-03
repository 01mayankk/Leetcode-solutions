class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {
        
        int n = robots.size();
        
        // These variables are used for binary search positions
        int pos1, pos2, pos3, leftPos, rightPos;
        
        // left[i]  -> walls destroyed if robot i shoots LEFT
        // right[i] -> walls destroyed if robot i shoots RIGHT
        // num[i]   -> walls between robot[i-1] and robot[i]
        vector<int> left(n, 0), right(n, 0), num(n, 0);
        
        // Map robot position -> distance (for easy lookup after sorting)
        unordered_map<int, int> robotsToDistance;
        for (int i = 0; i < n; i++) {
            robotsToDistance[robots[i]] = distance[i];
        }
        
        // Sort robots and walls
        sort(robots.begin(), robots.end());
        sort(walls.begin(), walls.end());
        
        // ----------- Preprocessing ----------- //
        for (int i = 0; i < n; i++) {
            
            // pos1 = index of first wall > robots[i]
            pos1 = upper_bound(walls.begin(), walls.end(), robots[i]) - walls.begin();
            
            // -------- LEFT SHOOT -------- //
            if (i >= 1) {
                // If there's a robot on left, bullet can't cross it
                // so take max of:
                // 1. robot[i] - distance
                // 2. previous robot + 1
                leftPos = lower_bound(
                    walls.begin(), walls.end(),
                    max(robots[i] - robotsToDistance[robots[i]],
                        robots[i - 1] + 1)
                ) - walls.begin();
            } else {
                // No robot on left → full range allowed
                leftPos = lower_bound(
                    walls.begin(), walls.end(),
                    robots[i] - robotsToDistance[robots[i]]
                ) - walls.begin();
            }
            
            // walls in [leftPos, pos1)
            left[i] = pos1 - leftPos;
            
            
            // -------- RIGHT SHOOT -------- //
            if (i < n - 1) {
                // If robot exists on right → limit before next robot
                rightPos = upper_bound(
                    walls.begin(), walls.end(),
                    min(robots[i] + robotsToDistance[robots[i]],
                        robots[i + 1] - 1)
                ) - walls.begin();
            } else {
                // No robot on right → full range
                rightPos = upper_bound(
                    walls.begin(), walls.end(),
                    robots[i] + robotsToDistance[robots[i]]
                ) - walls.begin();
            }
            
            // pos2 = first wall >= robots[i]
            pos2 = lower_bound(walls.begin(), walls.end(), robots[i]) - walls.begin();
            
            // walls in [pos2, rightPos)
            right[i] = rightPos - pos2;
            
            
            // -------- Walls between consecutive robots -------- //
            if (i == 0) continue;
            
            // pos3 = first wall >= robots[i-1]
            pos3 = lower_bound(walls.begin(), walls.end(), robots[i - 1]) - walls.begin();
            
            // number of walls strictly between robots[i-1] and robots[i]
            num[i] = pos1 - pos3;
        }
        
        
        // ----------- DP / Greedy Combination ----------- //
        
        // subLeft  = max walls till i if last robot shoots LEFT
        // subRight = max walls till i if last robot shoots RIGHT
        int subLeft = left[0];
        int subRight = right[0];
        
        int subLeftPrev, subRightPrev;
        
        for (int i = 1; i < n; i++) {
            
            int currentLeft, currentRight;
            
            // Case: robot i shoots LEFT
            currentLeft = max(
                subLeft + left[i],  // previous also LEFT
                
                // previous RIGHT → need to handle overlap carefully
                subRight - right[i - 1] +
                min(left[i] + right[i - 1], num[i])
            );
            
            // Case: robot i shoots RIGHT
            currentRight = max(
                subLeft + right[i],   // previous LEFT
                subRight + right[i]   // previous RIGHT
            );
            
            // Update for next iteration
            subLeft = currentLeft;
            subRight = currentRight;
        }
        
        // Final answer → best of last robot shooting LEFT or RIGHT
        return max(subLeft, subRight);
    }
};
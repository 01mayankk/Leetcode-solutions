class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minSteps = INT_MAX;

        // Traverse all elements in the array
        for (int i = 0; i < n; i++) {
            
            // Check if current word matches target
            if (words[i] == target) {
                
                // Calculate forward distance (clockwise)
                int forward = (i - startIndex + n) % n;
                
                // Calculate backward distance (anticlockwise)
                int backward = (startIndex - i + n) % n;
                
                // Take the minimum of both directions
                int steps = min(forward, backward);
                
                // Update minimum steps
                minSteps = min(minSteps, steps);
            }
        }

        // If target was never found, return -1
        return (minSteps == INT_MAX) ? -1 : minSteps;
    }
};

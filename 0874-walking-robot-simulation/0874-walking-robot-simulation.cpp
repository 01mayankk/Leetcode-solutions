class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        // 👉 Use unordered_set for O(1) lookup of obstacles
        unordered_set<long long> st;

        // 👉 Function to encode (x, y) into a unique long long
        // We store x in upper 32 bits and y in lower 32 bits
        auto encode = [](int x, int y) {
            return ((long long)x << 32) | (unsigned int)y;
        };

        // 👉 Insert all obstacles into the set
        for (auto &obs : obstacles) {
            st.insert(encode(obs[0], obs[1]));
        }

        // 👉 Directions: North, East, South, West
        // Each pair represents movement in (x, y)
        vector<pair<int,int>> dir = {
            {0, 1},   // North → y++
            {1, 0},   // East  → x++
            {0, -1},  // South → y--
            {-1, 0}   // West  → x--
        };

        int d = 0;       // 👉 Current direction index (start = North)
        int x = 0, y = 0; // 👉 Robot starts at origin (0,0)
        int maxDist = 0;  // 👉 Store max distance squared

        // 👉 Process each command
        for (int cmd : commands) {

            // 👉 Turn right
            if (cmd == -1) {
                d = (d + 1) % 4;
            }
            // 👉 Turn left
            else if (cmd == -2) {
                d = (d + 3) % 4; // equivalent to (d - 1 + 4) % 4
            }
            // 👉 Move forward cmd steps
            else {
                for (int step = 0; step < cmd; step++) {

                    // 👉 Next position
                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;

                    // 👉 If obstacle found → stop moving further
                    if (st.count(encode(nx, ny))) {
                        break;
                    }

                    // 👉 Otherwise move robot
                    x = nx;
                    y = ny;

                    // 👉 Update maximum Euclidean distance squared
                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }

        return maxDist;
    }
};
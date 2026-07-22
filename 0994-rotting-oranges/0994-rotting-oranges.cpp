class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        // Queue for Multi-Source BFS (stores all rotten oranges)
        queue<pair<int, int>> q;

        int r = grid.size();
        int c = grid[0].size();

        // Count of fresh oranges remaining
        int fresh = 0;

        // Traverse the grid once
        // - Push all initially rotten oranges into the queue
        // - Count the fresh oranges
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // If there are no fresh oranges, no time is needed
        if (fresh == 0) {
            return 0;
        }

        // Four possible movement directions
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        // Stores total minutes taken
        int time = 0;

        // Perform level-order BFS
        while (!q.empty()) {

            // Tracks whether at least one orange rots
            // during the current minute
            bool rotted = false;

            // Process all rotten oranges present at this minute
            int s = q.size();

            for (int k = 0; k < s; k++) {

                auto cell = q.front();
                q.pop();

                int x = cell.first;
                int y = cell.second;

                // Visit all four adjacent cells
                for (int i = 0; i < 4; i++) {

                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    // If the neighbour is inside the grid
                    // and is a fresh orange, rot it
                    if (nx >= 0 && nx < r &&
                        ny >= 0 && ny < c &&
                        grid[nx][ny] == 1) {

                        grid[nx][ny] = 2;     // Fresh -> Rotten
                        q.push({nx, ny});     // Process it in the next minute

                        fresh--;              // One less fresh orange
                        rotted = true;        // At least one orange rotted
                    }
                }
            }

            // If any orange became rotten in this level,
            // one minute has passed
            if (rotted) {
                time++;
            }
        }

        // If fresh oranges still remain,
        // they were unreachable
        if (fresh > 0) {
            return -1;
        }

        // Otherwise return total time taken
        return time;
    }
};
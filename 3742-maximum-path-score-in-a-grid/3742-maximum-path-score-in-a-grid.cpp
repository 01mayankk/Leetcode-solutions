class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        
        // Get number of rows
        int m = grid.size();
        
        // Get number of columns
        int n = grid[0].size();

        // 3D DP array:
        // dp[i][j][c] = maximum score to reach cell (i, j) with total cost exactly = c
        // Initialize all values to -1 (means not reachable)
        vector<vector<vector<int>>> dp(
            m, 
            vector<vector<int>>(n, vector<int>(k + 1, -1))
        );

        // Lambda function to compute cost of a cell
        // Rules:
        // 0 → cost 0
        // 1 → cost 1
        // 2 → cost 1
        auto getCost = [&](int val) {
            if (val == 0) return 0;  // no cost
            return 1;                // both 1 and 2 cost 1
        };

        // Lambda function to compute score of a cell
        // Score is equal to the value itself
        auto getScore = [&](int val) {
            return val;
        };

        // Starting position (0,0)
        // Given: grid[0][0] = 0 → score = 0, cost = 0
        dp[0][0][0] = 0;

        // Traverse each cell in row-major order
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Try all possible costs from 0 to k
                for (int c = 0; c <= k; c++) {

                    // If this state is not reachable, skip
                    if (dp[i][j][c] == -1) continue;

                    // ================= MOVE RIGHT =================
                    // Check if right cell exists
                    if (j + 1 < n) {

                        // Value of next cell
                        int cellVal = grid[i][j + 1];

                        // Cost and score of next cell
                        int cost = getCost(cellVal);
                        int score = getScore(cellVal);

                        // New total cost after moving
                        int newCost = c + cost;

                        // If cost is within allowed limit
                        if (newCost <= k) {

                            // Update DP:
                            // Take maximum score for this state
                            dp[i][j + 1][newCost] = max(
                                dp[i][j + 1][newCost],   // existing value
                                dp[i][j][c] + score      // new value
                            );
                        }
                    }

                    // ================= MOVE DOWN =================
                    // Check if down cell exists
                    if (i + 1 < m) {

                        // Value of next cell
                        int cellVal = grid[i + 1][j];

                        // Cost and score of next cell
                        int cost = getCost(cellVal);
                        int score = getScore(cellVal);

                        // New total cost after moving
                        int newCost = c + cost;

                        // If cost is within allowed limit
                        if (newCost <= k) {

                            // Update DP:
                            dp[i + 1][j][newCost] = max(
                                dp[i + 1][j][newCost],   // existing value
                                dp[i][j][c] + score      // new value
                            );
                        }
                    }
                }
            }
        }

        // Final answer: maximum score at destination (m-1, n-1)
        // considering all valid costs ≤ k
        int ans = -1;

        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m - 1][n - 1][c]);
        }

        // If no valid path found → ans will remain -1
        return ans;
    }
};
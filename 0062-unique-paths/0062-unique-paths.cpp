class Solution {
public:
    int uniquePaths(int m, int n) {
        // Step 1: Create a 2D DP table of size m x n
        // dp[i][j] represents the number of unique paths to reach cell (i,j)
        vector<vector<int>> dp(m, vector<int>(n, 1));  // Initialize all cells with 1

        // Step 2: Fill the DP table using the recurrence relation:
        // dp[i][j] = dp[i - 1][j] (from top) + dp[i][j - 1] (from left)
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // Step 3: Return the value in the bottom-right cell (destination)
        return dp[m - 1][n - 1];
    }
};

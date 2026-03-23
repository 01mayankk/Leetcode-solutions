class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();          // number of rows
        int n = grid[0].size();       // number of columns
        
        // maxDp[i][j] → maximum product to reach cell (i, j)
        // minDp[i][j] → minimum product to reach cell (i, j)
        // We track both because negative numbers can flip sign
        vector<vector<long long>> maxDp(m, vector<long long>(n));
        vector<vector<long long>> minDp(m, vector<long long>(n));
        
        // Base case: starting cell
        maxDp[0][0] = grid[0][0];
        minDp[0][0] = grid[0][0];
        
        // Fill first column (only one path: from top)
        for (int i = 1; i < m; i++) {
            maxDp[i][0] = maxDp[i - 1][0] * grid[i][0];
            minDp[i][0] = maxDp[i][0]; // same value since only one path
        }
        
        // Fill first row (only one path: from left)
        for (int j = 1; j < n; j++) {
            maxDp[0][j] = maxDp[0][j - 1] * grid[0][j];
            minDp[0][j] = maxDp[0][j]; // same logic
        }
        
        // Fill remaining cells
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long val = grid[i][j]; // current cell value
                
                // Possible products coming from top cell
                long long a = maxDp[i - 1][j] * val;
                long long b = minDp[i - 1][j] * val;
                
                // Possible products coming from left cell
                long long c = maxDp[i][j - 1] * val;
                long long d = minDp[i][j - 1] * val;
                
                // Choose maximum product among all possibilities
                maxDp[i][j] = max({a, b, c, d});
                
                // Choose minimum product among all possibilities
                minDp[i][j] = min({a, b, c, d});
            }
        }
        
        // Final result at bottom-right cell
        long long result = maxDp[m - 1][n - 1];
        
        // If maximum product is negative, no valid non-negative path
        if (result < 0) return -1;
        
        // Return result modulo 1e9+7 as required
        return result % 1000000007;
    }
};
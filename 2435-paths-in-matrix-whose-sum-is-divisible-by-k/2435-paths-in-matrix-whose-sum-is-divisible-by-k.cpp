class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {

        int n = grid.size();       // total rows
        int m = grid[0].size();    // total columns
        
        const int MOD = 1000000007; // to avoid overflow (take result % MOD)

        /*
            dp[i][j][r] = number of ways to reach cell (i, j)
                          such that the sum of values along the path % k = r

            Why 3D DP? 
            → Because from each cell the path sum can have multiple remainders.
              So we track all possible remainder states.
        */
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));

        /*
            Base Case:

            Starting at (0,0), only ONE path exists — we are already standing on it.
            Remainder = grid[0][0] % k
        */
        dp[0][0][grid[0][0] % k] = 1;

        // Traverse grid row-wise
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // For each remainder state possible at (i, j)
                for(int r = 0; r < k; r++) {
                    
                    int curr = dp[i][j][r];  // number of paths with remainder 'r' till now
                    if(curr == 0) continue;  // no path exists with this remainder → skip

                    /*
                        Move 1: DOWN (i+1, j)
                        New remainder = (current remainder + next cell value) % k
                    */
                    if(i+1 < n) {
                        int newR = (r + grid[i+1][j]) % k;
                        dp[i+1][j][newR] = (dp[i+1][j][newR] + curr) % MOD;
                    }

                    /*
                        Move 2: RIGHT (i, j+1)
                        New remainder = (current remainder + next cell value) % k
                    */
                    if(j+1 < m) {
                        int newR = (r + grid[i][j+1]) % k;
                        dp[i][j+1][newR] = (dp[i][j+1][newR] + curr) % MOD;
                    }
                }
            }
        }

        /*
            We need total paths whose total sum is divisible by k
            Divisible by k → remainder = 0

            So final answer is dp[last_row][last_col][0]
        */
        return dp[n-1][m-1][0];
    }
};

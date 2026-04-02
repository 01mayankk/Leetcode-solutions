class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        
        int m = coins.size();
        int n = coins[0].size();
        
        // dp[i][j][k] = max coins at (i,j) using k neutralizations
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        
        // Base case at (0,0)
        for(int k = 0; k < 3; k++) {
            if(coins[0][0] >= 0) {
                dp[0][0][k] = coins[0][0]; // no need to neutralize
            } else {
                if(k > 0)
                    dp[0][0][k] = 0; // neutralize robber
                else
                    dp[0][0][k] = coins[0][0]; // take loss
            }
        }
        
        // Fill DP
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;
                
                for(int k = 0; k < 3; k++) {
                    
                    int val = coins[i][j];
                    
                    // From top
                    if(i > 0) {
                        // Case 1: Do not neutralize
                        if(dp[i-1][j][k] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + val);
                        
                        // Case 2: Neutralize (only if negative)
                        if(val < 0 && k > 0 && dp[i-1][j][k-1] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1]);
                    }
                    
                    // From left
                    if(j > 0) {
                        // Case 1: Do not neutralize
                        if(dp[i][j-1][k] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k] + val);
                        
                        // Case 2: Neutralize
                        if(val < 0 && k > 0 && dp[i][j-1][k-1] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1]);
                    }
                }
            }
        }
        
        // Final answer = max among all k at destination
        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};
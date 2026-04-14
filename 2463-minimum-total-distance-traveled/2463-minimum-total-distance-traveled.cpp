class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        // Step 1: Sort robots and factories based on position
        // This helps in assigning nearest robots optimally
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        int n = robot.size();     // number of robots
        int m = factory.size();   // number of factories
        
        // dp[i][j] → minimum distance to assign first i robots using first j factories
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
        
        // Base case:
        // If there are 0 robots, cost is 0 regardless of factories
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }
        
        // Step 2: Fill DP table
        for (int j = 1; j <= m; j++) {
            
            // Current factory position and capacity
            int pos = factory[j - 1][0];
            int limit = factory[j - 1][1];
            
            for (int i = 0; i <= n; i++) {
                
                // Case 1: Skip current factory
                // (i robots handled by previous factories)
                dp[i][j] = dp[i][j - 1];
                
                long long cost = 0;  // stores cumulative cost
                
                // Case 2: Assign k robots to current factory
                // Try assigning 1 to limit robots
                for (int k = 1; k <= limit && i - k >= 0; k++) {
                    
                    // Add distance of assigning robot (i-k) to this factory
                    // We go backwards because we assign last k robots
                    cost += abs(robot[i - k] - pos);
                    
                    // If previous state is valid, update dp
                    if (dp[i - k][j - 1] != LLONG_MAX) {
                        dp[i][j] = min(
                            dp[i][j], 
                            dp[i - k][j - 1] + cost
                        );
                    }
                }
            }
        }
        
        // Final answer: all robots assigned using all factories
        return dp[n][m];
    }
};
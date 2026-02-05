class Solution {
public:
    int climbStairs(int n) {

        // Handle small cases explicitly
        if (n == 1) return 1;
        if (n == 2) return 2;

        // DP array of size (n + 1)
        vector<int> dp(n + 1);

        // Base cases
        dp[0] = 1;   // 1 way to stay at ground
        dp[1] = 1;   // 1 way to reach step 1
        dp[2] = 2;   // 2 ways to reach step 2

        // Build solution bottom-up
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // Answer stored at dp[n]
        return dp[n];
    }
};

class Solution {
public:
    int fib(int n) {

        // Base case:
        // If n is 0, Fibonacci number is 0
        if (n == 0) return 0;

        // Base case:
        // If n is 1, Fibonacci number is 1
        if (n == 1) return 1;

        // Create a DP array of size (n + 1)
        // dp[i] will store the ith Fibonacci number
        vector<int> dp(n + 1);

        // Initialize base Fibonacci values
        dp[0] = 0;
        dp[1] = 1;

        // Compute Fibonacci numbers from 2 to n
        // Each number is the sum of the previous two
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // Return the nth Fibonacci number
        return dp[n];
    }
};

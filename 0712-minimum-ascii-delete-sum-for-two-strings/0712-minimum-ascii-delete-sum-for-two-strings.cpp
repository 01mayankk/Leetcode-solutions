class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        // dp[i][j] = minimum ASCII delete sum to make
        // s1[0..i-1] and s2[0..j-1] equal
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case: if s2 is empty, delete all chars from s1
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }

        // Base case: if s1 is empty, delete all chars from s2
        for (int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    // Characters match, no cost
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Either delete from s1 or s2
                    dp[i][j] = min(
                        dp[i - 1][j] + s1[i - 1],
                        dp[i][j - 1] + s2[j - 1]
                    );
                }
            }
        }

        // Answer for full strings
        return dp[n][m];
    }
};

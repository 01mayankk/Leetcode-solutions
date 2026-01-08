class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // dp[i][j] = max dot product using nums1[0..i-1], nums2[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                int product = nums1[i - 1] * nums2[j - 1];

                // Option 1: take current pair alone
                int take = product;

                // Option 2: extend previous subsequence
                if (dp[i - 1][j - 1] != INT_MIN)
                    take = max(take, dp[i - 1][j - 1] + product);

                // Option 3: skip from either array
                dp[i][j] = max({take, dp[i - 1][j], dp[i][j - 1]});
            }
        }

        return dp[n][m];
    }
};

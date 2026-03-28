class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, '#');  // result string initialized with placeholder

        char ch = 'a';  // start assigning from 'a'

        // Step 1: Assign characters greedily
        for (int i = 0; i < n; i++) {
            if (s[i] == '#') {
                // assign new character
                if (ch > 'z') return "";  // only lowercase allowed
                s[i] = ch;

                // assign same char to all j where lcp[i][j] > 0
                for (int j = i + 1; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        s[j] = ch;
                    }
                }
                ch++;
            }
        }

        // Step 2: Validate LCP matrix
        // recompute LCP using DP
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // fill from bottom-right
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == s[j]) {
                    if (i == n - 1 || j == n - 1)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        // Step 3: Compare dp with given lcp
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] != lcp[i][j]) {
                    return "";  // invalid
                }
            }
        }

        return s;  // valid string
    }
};
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // Approach 1: Mathematical (O(1))
        // Since there is an even number of piles and an odd total sum,
        // Alice can always force picking all even-indexed or all odd-indexed piles.
        // One of these sums is strictly greater, meaning Alice can always win.
        // return true;

        // Approach 2: Dynamic Programming (O(N^2))
        int n = piles.size();
        
        // dp[i][j] stores the maximum score difference a player can achieve 
        // starting their turn with piles from index i to j.
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: When there is only 1 pile, the player takes it all.
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        // DP transitions: iterate over lengths of subarrays from 2 to n
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                
                // The current player chooses either the left pile (i) or the right pile (j).
                // They subtract the maximum difference the next player can get from the remaining piles.
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }

        // Alice wins if the maximum score difference for the entire array is greater than 0
        return dp[0][n - 1] > 0;
    }
};
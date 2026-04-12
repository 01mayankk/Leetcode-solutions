class Solution {
public:
    // Function to calculate distance between two characters
    int getDist(int a, int b) {
        if (a == -1) return 0; // If finger not used yet
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    // DP table: dp[index][f1][f2]
    int dp[301][27][27];

    int solve(string &word, int index, int f1, int f2) {
        // Base case: all characters typed
        if (index == word.size()) return 0;

        // Memoization check
        if (dp[index][f1 + 1][f2 + 1] != -1)
            return dp[index][f1 + 1][f2 + 1];

        int curr = word[index] - 'A';

        // Option 1: Use finger 1
        int useF1 = getDist(f1, curr) + solve(word, index + 1, curr, f2);

        // Option 2: Use finger 2
        int useF2 = getDist(f2, curr) + solve(word, index + 1, f1, curr);

        // Store minimum result
        return dp[index][f1 + 1][f2 + 1] = min(useF1, useF2);
    }

    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        
        // Initially both fingers are unused (-1)
        return solve(word, 0, -1, -1);
    }
};
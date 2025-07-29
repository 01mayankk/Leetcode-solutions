class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        // dp[i] tells whether we can reach the end from index i
        vector<bool> dp(n, false);
        
        // We can always reach the end from the last index
        dp[n - 1] = true;

        // Traverse from second last index to start
        for (int i = n - 2; i >= 0; --i) {
            // Calculate the farthest we can jump from current index
            int farthestJump = min(i + nums[i], n - 1);

            // Try all jumps from i to farthestJump
            for (int j = i + 1; j <= farthestJump; ++j) {
                if (dp[j]) {
                    dp[i] = true;  // We can reach end from index i
                    break;
                }
            }
        }

        // Return whether we can reach end from index 0
        return dp[0];
    }
};

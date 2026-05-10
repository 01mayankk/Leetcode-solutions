class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        
        int n = nums.size();

        // dp[i] = maximum jumps needed to reach index i
        // Initialize with very small value (unreachable)
        vector<int> dp(n, -1);

        // Starting index requires 0 jumps
        dp[0] = 0;

        // Try to reach every index i
        for (int i = 0; i < n; i++) {

            // If current index is unreachable, skip it
            if (dp[i] == -1) continue;

            // Try jumping from i -> j
            for (int j = i + 1; j < n; j++) {

                // Check jump condition
                long long diff = (long long)nums[j] - nums[i];

                if (diff >= -target && diff <= target) {

                    // Update maximum jumps for j
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        // If last index is unreachable, answer will remain -1
        return dp[n - 1];
    }
};
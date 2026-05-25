class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        
        int n = s.size();

        // dp[i] = true means we can reach index i
        vector<bool> dp(n, false);

        // Starting index is always reachable
        dp[0] = true;

        // This variable keeps track of how many reachable
        // positions are available in the current window
        int reachable = 0;

        // Start checking from index 1
        for(int i = 1; i < n; i++) {

            // Add new index entering the sliding window
            // Window start = i - maxJump
            if(i - minJump >= 0 && dp[i - minJump]) {
                reachable++;
            }

            // Remove old index leaving the sliding window
            // Window end = i - maxJump - 1
            if(i - maxJump - 1 >= 0 && dp[i - maxJump - 1]) {
                reachable--;
            }

            // Current index is reachable if:
            // 1. s[i] == '0'
            // 2. At least one reachable index exists in window
            if(s[i] == '0' && reachable > 0) {
                dp[i] = true;
            }
        }

        // Return whether last index is reachable
        return dp[n - 1];
    }
};
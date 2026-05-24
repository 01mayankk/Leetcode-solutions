class Solution {
public:

    // DFS function to calculate maximum jumps from current index
    int dfs(int idx, vector<int>& arr, int d, vector<int>& dp)
    {
        // If answer already calculated, return it
        if(dp[idx] != -1)
            return dp[idx];

        // Minimum answer is 1
        // (current index itself)
        int ans = 1;

        int n = arr.size();

        // ---------------- CHECK LEFT SIDE ----------------

        // Move left up to distance d
        for(int i = idx - 1; i >= max(0, idx - d); i--)
        {
            // Cannot jump if height is greater or equal
            // Also cannot cross such element
            if(arr[i] >= arr[idx])
                break;

            // Take maximum jumps possible
            ans = max(ans, 1 + dfs(i, arr, d, dp));
        }

        // ---------------- CHECK RIGHT SIDE ----------------

        // Move right up to distance d
        for(int i = idx + 1; i <= min(n - 1, idx + d); i++)
        {
            // Stop if taller or equal height found
            if(arr[i] >= arr[idx])
                break;

            // Update maximum answer
            ans = max(ans, 1 + dfs(i, arr, d, dp));
        }

        // Store answer in dp array
        return dp[idx] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        
        int n = arr.size();

        // DP array for memoization
        // dp[i] = maximum jumps starting from i
        vector<int> dp(n, -1);

        // Final result
        int result = 1;

        // Try every index as starting point
        for(int i = 0; i < n; i++)
        {
            result = max(result, dfs(i, arr, d, dp));
        }

        // Return maximum jumps possible
        return result;
    }
};
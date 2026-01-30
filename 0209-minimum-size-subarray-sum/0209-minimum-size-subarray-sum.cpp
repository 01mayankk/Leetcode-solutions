class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int left = 0;                  // Left pointer of sliding window
        int sum = 0;                   // Current window sum
        int minLen = INT_MAX;          // Store minimum subarray length
        
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];        // Expand window by adding right element
            
            // Try to shrink the window while sum >= target
            while (sum >= target) {
                minLen = min(minLen, right - left + 1); // Update answer
                sum -= nums[left];    // Remove left element from sum
                left++;               // Shrink window from left
            }
        }
        
        // If no valid subarray found, return 0
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};

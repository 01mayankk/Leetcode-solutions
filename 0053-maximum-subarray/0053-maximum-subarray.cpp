class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // Initialize both maxSum and currSum with first element
        // maxSum  -> stores the maximum subarray sum found so far
        // currSum -> stores the maximum subarray sum ending at current index
        int maxSum = nums[0];
        int currSum = nums[0];

        // Traverse the array starting from the second element
        for(int i = 1; i < nums.size(); i++)
        {
            // Decide whether to:
            // 1) Start a new subarray from nums[i]
            // 2) Extend the existing subarray
            currSum = max(nums[i], currSum + nums[i]);
            
            // Update the global maximum subarray sum
            maxSum = max(maxSum, currSum);
        }

        // Return the maximum subarray sum
        return maxSum;
    }
};

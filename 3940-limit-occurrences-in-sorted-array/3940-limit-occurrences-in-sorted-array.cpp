class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        
        // Edge case: if array is empty
        if(nums.empty()) 
            return {};

        // Count occurrences of current element
        int count = 1;

        vector<int> ans;

        // Add first element directly
        ans.push_back(nums[0]);

        // Traverse from second element
        for(int i = 1; i < nums.size(); i++)
        {
            // If current element is same as previous
            if(nums[i] == nums[i - 1] && count < k)
            {
                // Add element only if occurrences are less than k
                ans.push_back(nums[i]);

                // Increase occurrence count
                count++;
            }

            // If a new element is found
            else if(nums[i] != nums[i - 1])
            {
                // Add new element to answer
                ans.push_back(nums[i]);

                // Reset count for new element
                count = 1;
            }

            // If count already reached k,
            // we simply skip the element
        }

        // Return final modified array
        return ans;
    }
};
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        // This vector will store the final concatenated result
        vector<int> ans;

        // Store the size of the original array
        int len = nums.size();

        // We need to iterate 2 * len times
        // because we want to append the array to itself (nums + nums)
        for(int i = 0; i < 2 * len; i++)
        {
            // i % len ensures that:
            // - For first len elements, it copies normally
            // - For next len elements, it starts again from index 0
            // This effectively duplicates the array
            ans.push_back(nums[i % len]);
        }

        // Return the concatenated vector
        return ans;
    }
};
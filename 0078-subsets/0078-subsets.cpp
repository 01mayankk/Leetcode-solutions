class Solution {
public:

    // Recursive function to generate all subsets
    void getSubset(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result)
    {
        // Store the current subset (even if empty)
        result.push_back(current);

        // Loop through remaining elements to choose each one
        for(int i = start; i < nums.size(); i++)
        {
            current.push_back(nums[i]);            // Include nums[i] in subset
            getSubset(i + 1, nums, current, result); // Recurse for next elements

            current.pop_back();                    // Backtrack: remove last element
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;     // Final list of all subsets
        vector<int> current;            // Temporary list to build subsets

        getSubset(0, nums, current, result); // Start generating from index 0

        return result;                  // Return all generated subsets
    }
};

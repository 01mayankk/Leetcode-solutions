class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // Find the minimum and maximum elements to establish the full range
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        // Sort the array to allow sequential comparison
        sort(nums.begin(), nums.end());
        
        int idx = 0;
        vector<int> result;
        
        // Iterate through every integer in the expected range [mini, maxi]
        for(int i = mini; i <= maxi; i++) {
            // If the current expected number 'i' matches the element at nums[idx], 
            // advance the index pointer to check the next element in the array
            if(idx < nums.size() && nums[idx] == i) {
                idx++;
            } else {
                // If they don't match, 'i' is missing from the array
                result.push_back(i);
            }
        }

        return result;
    }
};
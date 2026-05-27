class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        // Create a copy of original array
        // because nums will be sorted later
        vector<int> copy(nums.begin(), nums.end());

        // Sort the array
        // Sorted order helps determine how many
        // numbers are smaller than a particular number
        sort(nums.begin(), nums.end());

        // HashMap:
        // key   -> number
        // value -> count of smaller numbers
        unordered_map<int, int> mp;

        // Traverse sorted array
        for(int i = 0; i < nums.size(); i++)
        {
            // Store only first occurrence
            // because first index in sorted array
            // equals count of smaller elements
            //
            // Example:
            // Sorted: [1,2,2,3,8]
            // First occurrence of 2 is at index 1
            // => only 1 number is smaller than 2
            if(mp.find(nums[i]) == mp.end())
            {
                mp[nums[i]] = i;
            }
        }

        // Final answer array
        vector<int> ans;

        // Traverse original array
        for(int num : copy)
        {
            // Push count of smaller numbers
            // using hashmap
            ans.push_back(mp[num]);
        }

        // Return final answer
        return ans;
    }
};
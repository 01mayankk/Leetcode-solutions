class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        // even index pointer → for positive numbers
        int even = 0;

        // odd index pointer → for negative numbers
        int odd = 1;

        int newSize = nums.size();

        // Create result array of same size
        // We pre-size it so we can assign using indices directly
        vector<int> result(newSize);

        // Traverse the original array
        for(int i = 0; i < nums.size(); i++)
        {
            // If current number is negative
            if(nums[i] < 0)
            {
                // Place it at next available odd index
                result[odd] = nums[i];

                // Move odd pointer to next odd index
                odd += 2;
            }
            else
            {
                // If number is positive, place at even index
                result[even] = nums[i];

                // Move even pointer to next even index
                even += 2;
            }
        }

        // Return rearranged array
        return result;
    }
};
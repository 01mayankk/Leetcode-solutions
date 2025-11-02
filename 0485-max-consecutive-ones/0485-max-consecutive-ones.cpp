class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count = 0; // Stores the maximum number of consecutive 1s found so far
        int one = 0;   // Temporary counter for the current sequence of consecutive 1s

        // Traverse the entire array
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                // Increment the current count of consecutive 1s
                one++;

                // Update the maximum count if current streak is longer
                if(count < one)
                {
                    count = one;
                }
            }
            else
            {
                // Reset current streak when a 0 is encountered
                one = 0;
            }
        }

        // Return the longest sequence of consecutive 1s
        return count;
    }
};

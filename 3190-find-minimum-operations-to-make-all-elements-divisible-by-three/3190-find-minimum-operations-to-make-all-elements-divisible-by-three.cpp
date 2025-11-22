class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0; // This will store how many numbers are NOT divisible by 3
        
        // Iterate through each element of the array
        for (int i = 0; i < nums.size(); i++)
        {
            // Check if the current number is NOT divisible by 3
            // (i.e., remainder is 1 or 2)
            if (nums[i] % 3 != 0)
            {
                count++;   // We need 1 operation to make this number divisible by 3
            }
        }

        // Return total operations needed
        return count;
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        // Index where the next non-zero element should be placed
        int nonZero = 0;

        // Traverse the entire array
        for(int i = 0; i < nums.size(); i++)
        {
            // If current element is non-zero
            if(nums[i] != 0)
            {
                // Swap current element with the position of nonZero index
                // This keeps all non-zero elements in relative order
                swap(nums[nonZero], nums[i]);

                // Move nonZero pointer to the next position
                nonZero++;
            }
        }
    }
};

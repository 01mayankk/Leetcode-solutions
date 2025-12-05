class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0;

        // Compute the total sum of the array
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        int leftSum = 0;   // Running sum of the left partition
        int count = 0;     // Count of valid partitions

        // We can only partition between index i and i+1
        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];           // Extend left partition
            int rightSum = totalSum - leftSum;  // Remaining sum becomes right partition

            // A partition is valid if leftSum and rightSum have the same parity (both even or both odd)
            if ((leftSum % 2) == (rightSum % 2)) {
                count++;   // Valid partition found
            }
        }

        return count;  // Return total number of valid partitions
    }
};

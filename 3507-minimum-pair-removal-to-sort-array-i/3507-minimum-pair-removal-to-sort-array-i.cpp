class Solution {
public:
    
    // ------------------------------------------------------------
    // Function: isNonDecreasing
    // Purpose : Checks whether the given array is non-decreasing
    // Meaning : nums[i] >= nums[i-1] for all valid i
    // ------------------------------------------------------------
    bool isNonDecreasing(const vector<int>& nums) {

        // Start checking from second element
        for (int i = 1; i < nums.size(); i++) {

            // If current element is smaller than previous,
            // array is NOT non-decreasing
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }

        // If no violation found, array is non-decreasing
        return true;
    }

    // ------------------------------------------------------------
    // Function: minimumPairRemoval
    // Purpose : Returns the minimum number of operations needed
    //           to make array non-decreasing
    // Operation:
    //   - Find adjacent pair with minimum sum (leftmost if tie)
    //   - Replace the pair with their sum
    // ------------------------------------------------------------
    int minimumPairRemoval(vector<int>& nums) {

        // Count number of operations performed
        int operations = 0;

        // Repeat operations until the array becomes non-decreasing
        while (!isNonDecreasing(nums)) {

            int minSum = INT_MAX; // Stores minimum adjacent sum
            int idx = -1;         // Stores index of left element of that pair

            // Traverse all adjacent pairs
            for (int i = 0; i < nums.size() - 1; i++) {

                // Calculate sum of adjacent elements
                int currSum = nums[i] + nums[i + 1];

                // Update minimum sum pair
                // Automatically picks leftmost pair if sums are equal
                if (currSum < minSum) {
                    minSum = currSum;
                    idx = i;
                }
            }

            // Merge the selected minimum-sum pair:
            // Replace nums[idx] with sum of the pair
            nums[idx] = nums[idx] + nums[idx + 1];

            // Remove the second element of the merged pair
            nums.erase(nums.begin() + idx + 1);

            // Increment operation count
            operations++;
        }

        // Return total operations needed
        return operations;
    }
};

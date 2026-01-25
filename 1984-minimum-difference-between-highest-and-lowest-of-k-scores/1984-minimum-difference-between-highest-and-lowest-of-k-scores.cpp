class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        // Edge case:
        // If we select only 1 student, the highest and lowest
        // score will be the same, so difference = 0
        if (k == 1) return 0;

        // Sort the array so that scores are in non-decreasing order
        // This helps us easily find the min and max in any group of k
        sort(nums.begin(), nums.end());

        // Initialize the answer with a very large value
        int minDiff = INT_MAX;

        // Use a sliding window of size k
        // i -> starting index of the window
        // i + k - 1 -> ending index of the window
        for (int i = 0; i + k - 1 < nums.size(); i++) {

            // Since the array is sorted:
            // nums[i]        -> minimum score in this window
            // nums[i+k-1]    -> maximum score in this window
            int currentDiff = nums[i + k - 1] - nums[i];

            // Update the minimum difference found so far
            minDiff = min(minDiff, currentDiff);
        }

        // Return the smallest difference among all k-sized groups
        return minDiff;
    }
};

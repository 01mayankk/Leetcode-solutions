class Solution {
public:
    int minSwaps(vector<int>& nums) {

        // Step 1: Count total number of 1s in the array
        int totalOnes = 0;
        for (int one : nums) {
            totalOnes += one;   // add 1 only when element is 1
        }

        // Edge cases:
        // If there are no 1s or all are 1s, no swaps needed
        if (totalOnes == 0 || totalOnes == nums.size()) {
            return 0;
        }

        // currOnes: number of 1s in current window
        // maxOnes : maximum number of 1s found in any valid window
        int currOnes = 0, maxOnes = 0;
        int len = nums.size();

        // Step 2: Sliding window over circular array
        for (int i = 0; i < 2 * len; i++) {

            // Add the current element to the window (right side)
            currOnes += nums[i % len];

            // If window size exceeds totalOnes,
            // remove the element that slides out from the left
            if (i >= totalOnes) {
                currOnes -= nums[(i - totalOnes) % len];
            }

            // Once window size reaches totalOnes,
            // update maximum 1s found so far
            if (i >= totalOnes - 1) {
                maxOnes = max(maxOnes, currOnes);
            }
        }

        // Minimum swaps = number of 0s in the best window
        return totalOnes - maxOnes;
    }
};

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        // Minimum possible divisor:
        // Divisor cannot be smaller than 1
        int start = 1;

        // Maximum possible divisor:
        // Using the largest element ensures sum <= nums.size()
        int end = *max_element(nums.begin(), nums.end());

        // Binary search on the divisor value
        while (start < end) {

            // Mid represents the candidate divisor
            int mid = start + (end - start) / 2;
            int sum = 0;

            // Compute the sum of ceil(nums[i] / mid)
            // Integer trick avoids floating-point precision issues
            for (int elem : nums) {
                sum += (elem + mid - 1) / mid;
            }

            // If the computed sum is within the threshold,
            // this divisor works, so try to find a smaller one
            if (sum <= threshold) {
                end = mid;
            }
            // If sum exceeds the threshold,
            // divisor is too small → increase it
            else {
                start = mid + 1;
            }
        }

        // start (or end) now holds the smallest valid divisor
        return start;
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        // Find the minimum and maximum element in the entire array
        long long mn = nums[0];
        long long mx = nums[0];

        for (int num : nums) {
            mn = min(mn, (long long)num);
            mx = max(mx, (long long)num);
        }

        // Maximum possible value of any subarray:
        // max(subarray) - min(subarray)
        //
        // A subarray containing both the global minimum and
        // global maximum elements will have value:
        // globalMax - globalMin.
        //
        // Since we are allowed to choose the same subarray
        // multiple times, the optimal strategy is to choose
        // a maximum-value subarray exactly k times.
        long long bestSubarrayValue = mx - mn;

        return bestSubarrayValue * k;
    }
};
class Solution {
public:

    // Helper function:
    // Counts number of subarrays with sum <= goal
    int atMost(vector<int>& nums, int goal) {

        // If goal becomes negative, no valid subarray exists
        if (goal < 0) return 0;

        int left = 0;         // left pointer of sliding window
        int sum = 0;          // current window sum
        int count = 0;        // number of valid subarrays

        // right pointer moves forward
        for (int right = 0; right < nums.size(); right++) {

            // expand window by including nums[right]
            sum += nums[right];

            // shrink window until sum <= goal
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }

            // all subarrays ending at 'right'
            // and starting from [left ... right] are valid
            count += right - left + 1;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        // exactly equal to goal =
        // subarrays with sum <= goal
        // minus
        // subarrays with sum <= goal - 1
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

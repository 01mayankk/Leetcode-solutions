class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        // Binary search boundaries
        int low = 0, high = nums.size() - 1;

        // Continue until the search space reduces to one element
        while (low < high) {

            // Find mid index safely (avoids overflow)
            int mid = low + (high - low) / 2;

            // Ensure mid is even
            // Reason: pairs always start at an even index
            if (mid % 2 == 1)
                mid--;

            // If nums[mid] and nums[mid + 1] form a valid pair,
            // then the single element must be on the right side
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            }
            // Otherwise, the single element is at mid or on the left side
            else {
                high = mid;
            }
        }

        // When low == high, it points to the single non-duplicate element
        return nums[low];
    }
};

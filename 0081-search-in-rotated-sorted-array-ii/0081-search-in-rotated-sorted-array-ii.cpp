class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // \U0001f3af Found target
            if (nums[mid] == target)
                return true;

            // ⚠️ Handle duplicates: can't determine which half is sorted
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            // ✅ Left half is sorted
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1; // search in left half
                else
                    left = mid + 1;  // search in right half
            }
            // ✅ Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;  // search in right half
                else
                    right = mid - 1; // search in left half
            }
        }

        return false;
    }
};

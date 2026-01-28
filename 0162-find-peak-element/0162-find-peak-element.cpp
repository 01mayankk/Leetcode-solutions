class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {

            int mid = start + (end - start) / 2;

            // If mid element is greater than next element,
            // then the peak lies on the left side (including mid)
            if (nums[mid] > nums[mid + 1]) {
                end = mid;
            }
            else {
                // Otherwise, peak lies on the right side
                start = mid + 1;
            }
        }

        // start == end → peak index
        return start;
    }
};

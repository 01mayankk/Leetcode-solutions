class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        // Start pointer (beginning of array)
        int left = 0;

        // End pointer (end of array)
        int right = arr.size() - 1;

        // Binary search until pointers meet
        while (left < right) {

            // Calculate mid safely to avoid overflow
            int mid = left + (right - left) / 2;

            // If current element is smaller than the next one,
            // we are on the increasing (ascending) slope
            if (arr[mid] < arr[mid + 1]) {
                // Peak lies to the right of mid
                left = mid + 1;
            }
            // Otherwise, we are on the decreasing slope or at the peak itself
            else {
                // Peak lies at mid or to the left of mid
                right = mid;
            }
        }

        // When left == right, it points to the peak index
        return left;
    }
};

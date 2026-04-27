class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // i -> last valid element in nums1
        // j -> last element in nums2
        // k -> last position in nums1 (total size m + n)
        int i = m - 1, j = n - 1, k = m + n - 1;

        // Compare from the back and place the larger element at position k
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];  // place nums1 element
                i--;
            } else {
                nums1[k] = nums2[j];  // place nums2 element
                j--;
            }
            k--; // move to next position
        }

        // If nums2 still has elements left, copy them
        // (No need to check nums1 because they are already in place)
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
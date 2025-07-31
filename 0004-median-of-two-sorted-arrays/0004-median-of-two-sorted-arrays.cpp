class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        // Ensure binary search is performed on the smaller array
        // This ensures time complexity is O(log(min(m, n)))
        if (A.size() > B.size()) return findMedianSortedArrays(B, A);

        int m = A.size();  // Size of the first (smaller) array
        int n = B.size();  // Size of the second (larger) array
        int low = 0, high = m;

        // Binary search on the smaller array
        while (low <= high) {
            // Partition A at index i
            int i = (low + high) / 2;

            // Partition B at index j such that total elements in left partition of A and B is (m + n + 1)/2
            // +1 ensures left side has one more element when total is odd
            int j = (m + n + 1) / 2 - i;

            // If i == 0, there are no elements on the left side of A
            // So maxLeftA is -∞
            int maxLeftA = (i == 0) ? INT_MIN : A[i - 1];

            // If i == m, there are no elements on the right side of A
            // So minRightA is +∞
            int minRightA = (i == m) ? INT_MAX : A[i];

            // Same logic applies for B
            int maxLeftB = (j == 0) ? INT_MIN : B[j - 1];
            int minRightB = (j == n) ? INT_MAX : B[j];

            // Check if we found a correct partition
            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                // Total number of elements is even
                if ((m + n) % 2 == 0) {
                    // Median is the average of max of left half and min of right half
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                } else {
                    // Total number of elements is odd
                    // Median is the max of left half
                    return max(maxLeftA, maxLeftB);
                }
            }
            // If maxLeftA > minRightB, we are too far on the right side of A
            // Move partition to the left
            else if (maxLeftA > minRightB) {
                high = i - 1;
            }
            // If maxLeftB > minRightA, we are too far on the left side of A
            // Move partition to the right
            else {
                low = i + 1;
            }
        }

     return 0;   
    }
};

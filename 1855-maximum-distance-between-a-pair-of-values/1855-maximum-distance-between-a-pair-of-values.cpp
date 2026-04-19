class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        // Pointer for nums1
        int i = 0;
        
        // Pointer for nums2
        int j = 0;
        
        // Sizes of arrays
        int n = nums1.size(), m = nums2.size();
        
        // Variable to store the maximum distance found
        int maxDist = 0;

        // Traverse both arrays using two pointers
        while (i < n && j < m) {
            
            // Check if current pair (i, j) is valid
            // Condition: nums1[i] <= nums2[j]
            if (nums1[i] <= nums2[j]) {
                
                // Valid pair → update maximum distance
                // j - i represents the distance
                maxDist = max(maxDist, j - i);
                
                // Move j forward to try increasing the distance
                j++;
            } 
            else {
                // Invalid pair → nums1[i] is too large
                
                // Move i forward to reduce nums1[i]
                // (since arrays are non-increasing)
                i++;
            }
        }

        // Return the maximum distance found
        return maxDist;
    }
};
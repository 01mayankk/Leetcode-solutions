class Solution {
public:
    
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        int i = 0; // Pointer for nums1
        int j = 0; // Pointer for nums2
        
        // Traverse both arrays
        while(i < nums1.size() && j < nums2.size()) {
            
            // If both elements are same,
            // we found the smallest common element
            if(nums1[i] == nums2[j]) {
                return nums1[i];
            }
            
            // Move the pointer of smaller element
            // to catch up with the larger one
            else if(nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }
        
        // No common element found
        return -1;
    }
};
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // The answer is always true regardless of the input array.
        // Case 1: If all numbers in nums1 are even, we simply assign nums2[i] = nums1[i] 
        // to make the entire nums2 array even.
        // Case 2: If there is at least one odd number in nums1 (let's say at index j), 
        // we can make the entire nums2 array odd:
        //   - For any index i where nums1[i] is odd, we set nums2[i] = nums1[i].
        //   - For any index i where nums1[i] is even, we set nums2[i] = nums1[i] - nums1[j].
        //     Subtracting an odd number from an even number always results in an odd number.
        return true;
    }
};
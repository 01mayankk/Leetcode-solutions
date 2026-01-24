class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int low = 0;                      // Boundary for 0s
        int mid = 0;                      // Current index
        int high = nums.size() - 1;       // Boundary for 2s
        
        // Process elements until mid crosses high
        while (mid <= high) {
            
            if (nums[mid] == 0) {
                // Place 0 at the correct position
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                // 1 is already in correct middle position
                mid++;
            }
            else { // nums[mid] == 2
                // Place 2 at the correct position
                swap(nums[mid], nums[high]);
                high--;
                // Do NOT increment mid here
                // because swapped element needs to be checked
            }
        }
    }
};

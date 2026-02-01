class Solution {
public:
    int minimumCost(vector<int>& nums) {

        // The first subarray must include nums[0],
        // so its contribution to cost is fixed
        int first = nums[0];
        
        // Variables to store the smallest and
        // second smallest elements from the remaining array
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        
        // Traverse from index 1 onwards
        // because nums[0] is already taken
        for (int i = 1; i < nums.size(); i++) {
            
            // If current element is smaller than min1,
            // update min2 first, then min1
            if (nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            } 
            // Else if current element lies between min1 and min2
            else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }
        
        // Total minimum cost is the sum of:
        // first element + two smallest elements from remaining array
        return first + min1 + min2;
    }
};

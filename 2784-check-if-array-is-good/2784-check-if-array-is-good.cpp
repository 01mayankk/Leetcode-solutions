class Solution {
public:
    
    // Function to check whether the array is "good"
    bool isGood(vector<int>& nums) {
        
        // Size of given array
        int n = nums.size();
        
        // Sort the array to compare easily
        sort(nums.begin(), nums.end());
        
        // For a good array:
        // nums should contain:
        // 1, 2, 3, ..., n-1
        // and the number (n-1) should appear twice
        
        // Check first n-1 elements
        for(int i = 0; i < n - 1; i++) {
            
            // Expected value at index i is (i + 1)
            if(nums[i] != i + 1) {
                return false;
            }
        }
        
        // Last element should also be (n - 1)
        if(nums[n - 1] != n - 1) {
            return false;
        }
        
        // If all conditions satisfied
        return true;
    }
};
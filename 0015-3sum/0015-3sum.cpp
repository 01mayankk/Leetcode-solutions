class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;  // To store final unique triplets
        
        // Step 1: Sort the array
        // Sorting helps in:
        // 1. Using two-pointer technique
        // 2. Easily skipping duplicates
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        // Step 2: Fix one element and find the other two using two pointers
        for(int i = 0; i < n - 2; i++) {
            
            // Skip duplicate elements for index i
            // This ensures unique triplets (avoid repeating same starting element)
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int left = i + 1;        // Pointer just after i
            int right = n - 1;       // Pointer at the end
            
            // Step 3: Two-pointer approach
            while(left < right) {
                
                int sum = nums[i] + nums[left] + nums[right];
                
                if(sum == 0) {
                    // Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for left pointer
                    // Move left forward while next element is same
                    while(left < right && nums[left] == nums[left + 1])
                        left++;
                    
                    // Skip duplicates for right pointer
                    // Move right backward while previous element is same
                    while(left < right && nums[right] == nums[right - 1])
                        right--;
                    
                    // Move both pointers after processing current pair
                    left++;
                    right--;
                }
                else if(sum < 0) {
                    // Current sum is too small → need a larger value
                    // Move left pointer to the right
                    left++;
                }
                else {
                    // Current sum is too large → need a smaller value
                    // Move right pointer to the left
                    right--;
                }
            }
        }
        
        // Return all unique triplets
        return result;
    }
};
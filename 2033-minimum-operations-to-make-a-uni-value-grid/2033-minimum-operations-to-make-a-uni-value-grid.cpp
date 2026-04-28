class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        
        // Step 1: Flatten the grid into a 1D array
        for (auto &row : grid) {
            for (auto &val : row) {
                nums.push_back(val);
            }
        }
        
        // Step 2: Sort the array
        sort(nums.begin(), nums.end());
        
        // Step 3: Take median as target
        int n = nums.size();
        int target = nums[n / 2];
        
        int operations = 0;
        
        // Step 4: Check feasibility + count operations
        for (int num : nums) {
            
            // If difference not divisible by x → impossible
            if (abs(num - target) % x != 0) {
                return -1;
            }
            
            // Add required operations
            operations += abs(num - target) / x;
        }
        
        return operations;
    }
};
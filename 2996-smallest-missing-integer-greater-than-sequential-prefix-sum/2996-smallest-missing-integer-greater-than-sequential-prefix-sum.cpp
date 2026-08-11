class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // Initialize the sum with the first element of the array
        int prefix_sum = nums[0];
        
        // Find the longest sequential prefix and calculate its sum
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                prefix_sum += nums[i];
            } else {
                // Break as soon as the sequential property is broken
                break; 
            }
        }
        
        // Use an unordered_set for fast O(1) lookups of existing elements in the array
        unordered_set<int> seen(nums.begin(), nums.end());
        
        // Find the smallest missing integer greater than or equal to the prefix sum
        int x = prefix_sum;
        while (seen.count(x)) {
            x++;
        }
        
        return x;
    }
};
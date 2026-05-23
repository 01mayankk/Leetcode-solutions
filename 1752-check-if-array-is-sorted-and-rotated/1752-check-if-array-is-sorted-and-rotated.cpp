class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        
        // Count how many times the order decreases
        // Example: 3 4 5 1 2 → decrease occurs at 5 > 1
        int count = 0;

        for (int i = 0; i < n; i++) {
            
            // Compare current element with next element
            // Use modulo (%) to connect last element with first
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        // For a sorted and rotated array,
        // there can be at most one decreasing point
        return count <= 1;
    }
};
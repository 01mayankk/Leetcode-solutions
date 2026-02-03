class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        // Need at least 4 numbers to form 3 segments
        if (n < 4) return false;
        
        int i = 0;
        
        // 1) First strictly increasing part
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        // p must be > 0 and less than n - 2
        if (i == 0 || i >= n - 2) return false;
        
        // 2) Strictly decreasing part
        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }
        // q must be > p and less than n - 1
        if (i >= n - 1) return false;
        
        // 3) Final strictly increasing part
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        
        // If we've reached the end successfully, it's trionic
        return (i == n - 1);
    }
};

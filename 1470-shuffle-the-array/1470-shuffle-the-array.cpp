class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> ans(2 * n);   // Pre-allocate size
        
        // x part: 0 → n-1
        // y part: n → 2n-1
        for(int i = 0; i < n; i++) {
            ans[2*i]     = nums[i];       // x elements
            ans[2*i + 1] = nums[i + n];   // y elements
        }
        
        return ans;
    }
};
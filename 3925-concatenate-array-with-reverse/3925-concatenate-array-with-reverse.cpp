class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {

        int n = nums.size();

        // Create result array of size 2*n
        vector<int> ans(2 * n);

        for (int i = 0; i < n; i++) {

            // First half same as nums
            ans[i] = nums[i];

            // Second half in reverse order
            ans[i + n] = nums[n - i - 1];
        }

        return ans;
    }
};
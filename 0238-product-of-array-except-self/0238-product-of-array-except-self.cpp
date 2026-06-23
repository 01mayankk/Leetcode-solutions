class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // This will store the final answer.
        vector<int> ans(n, 1);

        // -------------------------------
        // Step 1: Store prefix products
        // -------------------------------
        // ans[i] will contain the product
        // of all elements to the left of i.

        int prefix = 1;

        for (int i = 0; i < n; i++) {
            ans[i] = prefix;      // product of elements before i
            prefix *= nums[i];    // update prefix for next index
        }

        // Example:
        // nums = [1,2,3,4]
        // ans  = [1,1,2,6]

        // -------------------------------
        // Step 2: Multiply suffix products
        // -------------------------------
        // suffix stores the product of all
        // elements to the right of i.

        int suffix = 1;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;     // left product * right product
            suffix *= nums[i];    // update suffix
        }

        // Example:
        // ans before suffix pass = [1,1,2,6]
        //
        // i = 3 -> ans[3] = 6 * 1  = 6
        // suffix = 4
        //
        // i = 2 -> ans[2] = 2 * 4  = 8
        // suffix = 12
        //
        // i = 1 -> ans[1] = 1 * 12 = 12
        // suffix = 24
        //
        // i = 0 -> ans[0] = 1 * 24 = 24

        return ans;
    }
};
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        // Standard large prime modulus used in competitive programming
        const int MOD = 1e9 + 7;
        
        // Iterate over each query
        for (auto &q : queries) {
            int l = q[0];  // left index
            int r = q[1];  // right index
            int k = q[2];  // step size
            int v = q[3];  // multiplier
            
            // Start from index l and jump by k each time
            for (int idx = l; idx <= r; idx += k) {
                
                // Multiply current value with v
                // 1LL is used to convert int → long long BEFORE multiplication
                // This prevents overflow (since int * int may exceed 32-bit range)
                long long updated = (1LL * nums[idx] * v) % MOD;
                
                // Store back as int after modulo
                nums[idx] = (int)updated;
            }
        }
        
        // Compute XOR of all elements in final array
        int result = 0;
        for (int num : nums) {
            result ^= num;  // XOR accumulation
        }
        
        return result;
    }
};
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
        // Base case for n = 1: only possible XOR triplet value is 1 (1 ^ 1 ^ 1)
        if (n == 1) {
            return 1;
        }
        
        // Base case for n = 2: possible unique XOR triplet values are {1, 2}
        if (n == 2) {
            return 2;
        }
        
        // For n >= 3, any integer in the range [0, 2^(msb(n) + 1) - 1] 
        // can be generated as a XOR triplet from the numbers [1, n].
        // Therefore, the total number of unique values is 2^(msb(n) + 1).
        int msb = 31 - __builtin_clz(n);
        return 1 << (msb + 1);
    }
};
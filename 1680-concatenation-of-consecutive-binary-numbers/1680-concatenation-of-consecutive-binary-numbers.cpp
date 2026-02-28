class Solution {
public:
    int concatenatedBinary(int n) {
        
        const int MOD = 1e9 + 7;  // Required modulo
        long long result = 0;     // Use long long to prevent overflow
        int bitLength = 0;        // To track number of bits of current number
        
        for(int i = 1; i <= n; i++) {
            
            // If i is a power of 2, its bit length increases by 1
            // Example: 1(1), 2(10), 4(100), 8(1000) ...
            if((i & (i - 1)) == 0) {
                bitLength++;
            }
            
            // Left shift result by bitLength
            // This makes space for current number's binary
            result = ((result << bitLength) % MOD + i) % MOD;
        }
        
        return result;
    }
};
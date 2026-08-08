class Solution {
public:
    int largestInteger(int n, int s) {
        // If the required sum is greater than the maximum possible sum 
        // with n digits (all 9s), no such integer exists.
        if (s > n * 9) {
            return -1;
        }
        
        // If the required sum is 0, the only non-negative integer is 0.
        if (s == 0) {
            return 0;
        }
        
        int result = 0;
        
        // Greedily build the number from left to right to maximize it.
        // We use exactly n digits (padding with 0s at the end if needed) 
        // to make the integer as large as possible.
        for (int i = 0; i < n; ++i) {
            // Take the maximum possible valid digit (up to 9 or remaining sum)
            int digit = min(9, s);
            
            // Append the digit to our result
            result = result * 10 + digit;
            
            // Subtract the used digit from the remaining sum
            s -= digit;
        }
        
        return result;
    }
};
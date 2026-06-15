class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        
        // Lower limit of the range [n-k, n+k]
        int first = n - k;

        // Upper limit of the range [n-k, n+k]
        int last = n + k;

        // Variable to store the final sum
        int sum = 0;

        // Compatible integers must be positive
        // If n-k is less than 1, start from 1
        if (first < 1) {
            first = 1;
        }

        // Check every integer in the valid range
        for (int i = first; i <= last; i++) {

            // Compute bitwise AND of n and i
            int andVal = n & i;

            // A compatible integer must satisfy:
            // (n & i) == 0
            // i.e., n and i should not have any common set bit
            if (andVal == 0) {
                sum += i;
            }
        }

        // Return the sum of all compatible integers
        return sum;
    }
};
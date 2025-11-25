class Solution {
public:
    int smallestRepunitDivByK(int K) {

        // A repunit is a number made only of '1's -> 1, 11, 111, 1111, ...
        // Such numbers can NEVER be divisible by 2 or 5 because:
        // - Divisible by 2 → last digit must be even
        // - Divisible by 5 → last digit must be 0 or 5
        // All repunits end with '1', so return -1 immediately.
        if (K % 2 == 0 || K % 5 == 0) 
            return -1;

        int remainder = 0;  // Will store the remainder of the repunit mod K

        // Key idea:
        // Instead of building the actual number (which becomes super large),
        // we simulate it using mod property:
        //    next_number = previous_number * 10 + 1
        // Taking mod K at every step avoids overflow.
        //
        // At most, we will see K different remainders (0 to K-1).
        // If we don't hit remainder == 0 within K steps, a cycle has formed
        // and no answer exists.

        for (int length = 1; length <= K; length++) {

            // Build the next repunit's remainder:
            // Example: remainder of 11 is (remainder of 1 * 10 + 1) % K
            remainder = (remainder * 10 + 1) % K;

            // If the remainder ever becomes 0, the repunit is divisible by K.
            // The 'length' is the number of digits (i.e., count of '1's).
            if (remainder == 0)
                return length;
        }

        // If loop ends, then no repunit divisible by K exists.
        return -1;
    }
};

class Solution {
public:
    int divide(int dividend, int divisor) {

        // ----------------------------------------------------------
        // Special case:
        // INT_MIN = -2147483648
        // abs(INT_MIN) cannot be represented as int.
        // INT_MIN / -1 = 2147483648 (overflow)
        // According to the problem, return INT_MAX.
        // ----------------------------------------------------------
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // ----------------------------------------------------------
        // Convert both numbers to long long to avoid overflow
        // while taking absolute values.
        // ----------------------------------------------------------
        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);

        long long quotient = 0;

        // ----------------------------------------------------------
        // Keep subtracting the largest possible multiple of divisor.
        // Example:
        // dividend = 43, divisor = 3
        //
        // 3,6,12,24 (largest <=43)
        // subtract 24
        //
        // remaining = 19
        // again find largest multiple...
        // ----------------------------------------------------------
        while (dvd >= dvs) {

            long long temp = dvs;   // Current multiple of divisor
            long long multiple = 1; // Corresponding quotient value

            // ------------------------------------------------------
            // Double the divisor until it becomes just smaller than
            // the remaining dividend.
            // ------------------------------------------------------
            while ((temp << 1) <= dvd) {
                temp <<= 1;         // temp *= 2
                multiple <<= 1;     // multiple *= 2
            }

            // Subtract that largest multiple
            dvd -= temp;

            // Add its contribution to the answer
            quotient += multiple;
        }

        // ----------------------------------------------------------
        // Determine the sign of the answer.
        // If signs are different -> negative.
        // Otherwise -> positive.
        // ----------------------------------------------------------
        if ((dividend < 0) ^ (divisor < 0))
            quotient = -quotient;

        return (int)quotient;
    }
};
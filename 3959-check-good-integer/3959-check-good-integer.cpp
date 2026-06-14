class Solution {
public:
    bool checkGoodInteger(int n) {

        // Stores the sum of squares of digits
        long long sqSum = 0;

        // Stores the sum of digits
        long long sum = 0;

        // Create a copy so that original n remains unchanged
        int copy = n;

        // Extract digits one by one
        while (copy > 0) {

            // Get the last digit
            int digit = copy % 10;

            // Add digit to the digit sum
            sum += digit;

            // Add square of digit to the square sum
            sqSum += (digit * digit);

            // Remove the last digit
            copy /= 10;
        }

        // Calculate the difference:
        // (sum of squares of digits) - (sum of digits)
        long long result = sqSum - sum;

        // If the difference is at least 50,
        // the integer is considered "good"
        if (result >= 50) {
            return true;
        }

        // Otherwise, it is not a good integer
        return false;
    }
};
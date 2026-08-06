class Solution {
public:
    int smallestNumber(int n, int t) {
        // Loop indefinitely until the satisfying number is found
        while (true) {
            int product = 1;
            int num = n;
            
            // Calculate the product of the digits of the current number
            while (num > 0) {
                int digit = num % 10; // Extract the rightmost digit
                product *= digit;     // Multiply the digit to the product
                num /= 10;            // Remove the rightmost digit
            }
            
            // If the digit product is divisible by t, we found our answer
            if (product % t == 0) {
                return n;  
            }
            
            // Otherwise, increment n to check the next number
            n++;
        }
    }
};
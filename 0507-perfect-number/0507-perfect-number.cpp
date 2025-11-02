class Solution {
public:
    bool checkPerfectNumber(int num) {
        // A perfect number is a number equal to the sum of its positive divisors (excluding itself)
        // Example: 28 -> 1 + 2 + 4 + 7 + 14 = 28

        // Base case: 1 is not a perfect number
        if (num == 1) return false;

        int sum = 1; // Start with 1 (since 1 is always a divisor)

        // Check all divisors from 2 up to num / 2
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                sum += i; // Add divisor to the sum
            }
        }

        // If the sum of divisors equals the original number, it's perfect
        if (num == sum) {
            return true;
        }

        return false;
    }
};

// class Solution {  // This is most optimized code for this problem as we are going for square root of the number to be more optimized
// public:
//     bool checkPerfectNumber(int num) {
//         // A perfect number is a number equal to the sum of its positive divisors (excluding itself)
//         // Example: 28 -> 1 + 2 + 4 + 7 + 14 = 28

//         // Base case: 1 is not a perfect number
//         if (num <= 1) return false;

//         int sum = 1; // Start with 1, since 1 is always a divisor

//         // Loop only up to sqrt(num) to find divisors efficiently
//         for (int i = 2; i * i <= num; i++) {
//             if (num % i == 0) {
//                 sum += i; // Add divisor 'i'

//                 int other = num / i;
//                 if (other != i) { 
//                     // Add the paired divisor (num / i), 
//                     // but avoid double-counting when i == num / i (perfect square)
//                     sum += other;
//                 }
//             }
//         }

//         // A number is perfect if the sum of its divisors equals itself
//         return sum == num;
//     }
// };


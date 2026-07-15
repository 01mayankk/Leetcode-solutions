// class Solution {
// public:
//     int gcdOfOddEvenSums(int n) {

//         // Sum of the first n odd numbers = n²
//         int oddSum = n * n;

//         // Sum of the first n even numbers = n(n + 1)
//         int evenSum = n * (n + 1);

//         // Return the GCD of both sums
//         return gcd(oddSum, evenSum);
//     }
// };


class Solution {
public:
    int gcdOfOddEvenSums(int n) {

        // gcd(n², n(n+1))
        // = n * gcd(n, n+1)
        // Consecutive numbers are always coprime.
        // Therefore, gcd = n.

        return n;
    }
};
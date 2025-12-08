// class Solution {
// public:
//     int countTriples(int n) { 
//         int count = 0;

//          // This brute-force approach is NOT efficient because it checks all (a, b, c)
//                     // combinations using three nested loops, resulting in O(n^3) time complexity.
//                     // The optimized solutions remove the third loop by calculating c = sqrt(a^2 + b^2),
//                     // reducing the complexity to O(n^2), making them far faster.
//                     if (a * a + b * b == c * c) {
//         // Total combinations = n * n * n = O(n^3)
//         for (int a = 1; a <= n; a++) {
//             for (int b = 1; b <= n; b++) {
//                 for (int c = 1; c <= n; c++) {

//                     // Check if the Pythagorean condition holds:
//                     // a^2 + b^2 = c^2
//                     if (a * a + b * b == c * c) {
//                         count++;
//                     }
//                 }
//             }
//         }

//         // Return the number of valid triples
//         return count;
//     }
// };

// class Solution {
// public:
//     int countTriples(int n) {
//         int count = 0;  // To store the total number of valid triples
        
//         // Loop over all possible values of 'a'
//         for (int a = 1; a <= n; a++) {

//             // Loop over all possible values of 'b'
//             for (int b = 1; b <= n; b++) {

//                 // Compute a^2 + b^2
//                 int c2 = a * a + b * b;

//                 // Compute c = sqrt(a^2 + b^2)
//                 int c = sqrt(c2);

//                 // Check if 'c' is a valid integer and within range
//                 // c*c == c2 → ensures perfect square
//                 // c <= n     → ensures c is within allowed bounds
//                 //
//                 // This method is better than O(n^3) brute force because we
//                 // eliminate the third loop entirely by computing 'c' directly,
//                 // reducing time complexity to O(n^2). However, it's still not
//                 // the best approach because we repeatedly compute squares and
//                 // call sqrt() inside the loops—precomputing squares avoids
//                 // repeated work and improves efficiency further.
//                 if (c * c == c2 && c <= n) {
//                     count++;  // Found a valid (a, b, c) triple
//                 }
//             }
//         }

//         return count; // Return total valid triples
//     }
// };

class Solution {
public:
    int countTriples(int n) {

        // Precompute squares of all numbers from 1 to n
        // sq[i] = i*i to avoid recalculating squares repeatedly
        vector<int> sq(n + 1);
        for (int i = 1; i <= n; i++)
            sq[i] = i * i;

        int count = 0;

        // Try every pair (a, b)
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {

                // Compute c^2 = a^2 + b^2
                int c2 = sq[a] + sq[b];

                // Compute integer c = sqrt(c^2)
                int c = sqrt(c2);

                // Check:
                // 1. c*c == c2 → c must be a perfect square root
                // 2. c <= n     → c must be within allowed range
                if (c <= n && c * c == c2)
                    count++;
            }
        }

        // Return the number of valid triples (a, b, c)
        return count;
    }
};

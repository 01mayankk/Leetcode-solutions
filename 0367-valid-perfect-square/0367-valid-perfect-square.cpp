class Solution {
public:
    bool isPerfectSquare(int num) {

        // Handle small edge cases
        if (num == 1) return true;

        // Start of binary search range
        long long start = 1;

        // End of binary search range
        long long end = num;

        // Binary search to find an integer whose square is num
        while (start <= end) {

            // Mid value (safe from overflow)
            long long mid = start + (end - start) / 2;

            // Square of mid (use long long to avoid overflow)
            long long square = mid * mid;

            // Perfect square found
            if (square == num) {
                return true;
            }
            // mid^2 is smaller, search right half
            else if (square < num) {
                start = mid + 1;
            }
            // mid^2 is larger, search left half
            else {
                end = mid - 1;
            }
        }

        // No integer square found
        return false;
    }
};

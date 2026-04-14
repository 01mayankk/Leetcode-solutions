class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;  // Variable to store total occurrences of the digit

        // Traverse through each number in the array
        for (int num : nums) {

            // Edge case:
            // If the number is 0 and digit is also 0,
            // then '0' appears once
            if (num == 0 && digit == 0) {
                count++;
            }

            // Extract digits one by one using modulo
            while (num > 0) {

                // Check if the last digit matches the given digit
                if (num % 10 == digit) {
                    count++;  // Increment count if match found
                }

                // Remove the last digit
                num /= 10;
            }
        }

        // Return total count of digit occurrences
        return count;

    }
};
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;  // Pointer for num1 (starting from the last digit)
        int j = num2.size() - 1;  // Pointer for num2 (starting from the last digit)
        int carry = 0;            // To store carry during addition
        string result = "";       // To store the resulting sum (in reverse)

        // Loop until both numbers are processed or carry remains
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;  // Start with previous carry

            // Add digit from num1 if available
            if (i >= 0) {
                sum += num1[i] - '0'; // Convert char to int
                i--;
            }

            // Add digit from num2 if available
            if (j >= 0) {
                sum += num2[j] - '0'; // Convert char to int
                j--;
            }

            // Get current digit and update carry
            result.push_back((sum % 10) + '0'); // Convert back to char
            carry = sum / 10;
        }

        // Since result is built backwards, reverse it
        reverse(result.begin(), result.end());

        return result;
    }
};

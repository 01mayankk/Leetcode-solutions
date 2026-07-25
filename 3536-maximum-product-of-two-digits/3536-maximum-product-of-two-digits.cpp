class Solution {
public:
    int maxProduct(int n) {

        // Convert the number into a string so we can iterate over each digit
        string s = to_string(n);

        // Store the largest and second largest digits found so far
        int maxi = -1, maxi2 = -1;

        // Traverse every digit in the string
        for (char c : s) {

            // Convert character ('0' - '9') into its integer value
            int digit = c - '0';

            // If the current digit is the largest seen so far
            if (digit > maxi) {

                // Previous largest becomes the second largest
                maxi2 = maxi;

                // Update the largest digit
                maxi = digit;

            }
            // Otherwise, check if it should become the second largest
            else if (digit > maxi2) {

                // Update the second largest digit
                maxi2 = digit;
            }
        }

        // Return the product of the two largest digits
        return maxi * maxi2;
    }
};
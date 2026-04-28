class Solution {
public:
    bool validDigit(int n, int x) {
        
        int copy = n;

        // Flag to check if digit 'x' is present in number
        bool present = false;

        // Flag to check if the most significant digit is NOT equal to x
        bool first = false;

        // Step 1: Check if digit 'x' exists anywhere in the number
        while(copy > 0)
        {
            if(copy % 10 == x)   // check last digit
            {
                present = true;
                break;           // stop once found
            }
            copy /= 10;          // remove last digit
        }

        // Reset copy to original number
        copy = n;

        // Step 2: Check the most significant digit (first digit)
        while(copy > 0)
        {
            // When number becomes single digit, it's the first digit
            if(copy <= 9 && copy != x)
            {
                first = true;    // first digit is NOT equal to x
            }
            copy /= 10;          // keep removing digits
        }

        // Step 3: Return true only if:
        // - digit x is present somewhere
        // - first digit is not equal to x
        if(first && present)
        {
            return true;
        }

        return false; // otherwise false
        
    }
};
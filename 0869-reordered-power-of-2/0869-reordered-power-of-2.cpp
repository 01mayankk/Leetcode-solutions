class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // Lambda function to count and sort digits of a number
        // This will help in comparing if two numbers are made of the same digits
        auto countDigits = [](int x) {
            string s = to_string(x);    // Convert integer 'x' to string
            sort(s.begin(), s.end());   // Sort the digits in ascending order
            return s;                   // Return sorted string of digits
        };

        // Get the sorted digit sequence of the given number 'n'
        string target = countDigits(n);

        // Loop through all powers of 2 that fit within a 32-bit integer
        // 1 << i means 2^i
        for (int i = 0; i < 31; i++) {
            // If the sorted digit sequence of 2^i matches 'n', return true
            // This means the digits of 'n' can be rearranged to form 2^i
            if (countDigits(1 << i) == target) 
                return true;
        }

        // If no power of 2 matches, return false
        return false;
    }
};

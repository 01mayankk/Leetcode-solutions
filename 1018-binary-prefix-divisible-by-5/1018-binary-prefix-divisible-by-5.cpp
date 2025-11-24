// class Solution {
// public:
//     vector<bool> prefixesDivBy5(vector<int>& nums) { // This code is failing because value is goinng beyond the range even it is long long type so whwn we do modulo 5 it gives overflow.
        
//         long long value = 0;          // Will store the numeric value of the prefix (in binary)
//         vector<bool> result;          // To store whether each prefix is divisible by 5

//         for (int bit : nums) {
//             // Shift existing number left by 1 (multiply by 2) and add current bit
//             // This efficiently builds the decimal number from binary bits
//             value = (value << 1) | bit;

//             // Check divisibility of current prefix by 5
//             // If divisible, push true, else false
//             if (value % 5 == 0)
//                 result.push_back(true);
//             else
//                 result.push_back(false);
//         }

//         return result; // Return results for all prefixes
//     }
// };

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        
        // Instead of storing the full binary number (which becomes extremely large),
        // we only store the current prefix value modulo 5.
        // Why? Because we only care if the number is divisible by 5,
        // and (A % 5) == (A mod 5) always holds regardless of how large A becomes.
        int value = 0;

        vector<bool> result;  // Stores true/false for each prefix

        for (int bit : nums) {

            // Build the number using binary logic:
            // Normally: newNumber = oldNumber * 2 + bit
            // But to avoid overflow, we take modulo 5 at each step.
            // This works because:
            //    ( (old * 2 + bit) % 5 ) == (newNumber % 5)
            //
            // Also using (value << 1) is equivalent to multiplying by 2.
            value = ((value << 1) + bit) % 5;

            // If the remainder is 0, the current binary prefix forms
            // a number divisible by 5 → push true, else false.
            result.push_back(value == 0);
        }

        // Return the result vector containing divisibility info
        return result;
    }
};

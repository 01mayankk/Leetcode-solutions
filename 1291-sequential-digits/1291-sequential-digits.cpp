// class Solution {
// public:
//     vector<int> sequentialDigits(int low, int high) {

//         // Stores all sequential digit numbers within the given range
//         vector<int> result;

//         // Check every number from low to high
//         for (int i = low; i <= high; i++) {

//             // Convert the current number to a string for easy digit comparison
//             string s = to_string(i);

//             int idx = 0;

//             // Flag to determine whether the current number has sequential digits
//             bool possible = false;

//             // Compare every adjacent pair of digits
//             while (idx < s.size() - 1) {

//                 // Check if the next digit is exactly one greater than the current digit
//                 // Example: 1 -> 2, 2 -> 3, 7 -> 8
//                 if (s[idx] - '0' == (s[idx + 1] - '0') - 1) {
//                     possible = true;
//                 }
//                 else {
//                     // Sequence breaks, so this number is not valid
//                     possible = false;
//                     break;
//                 }

//                 idx++;
//             }

//             // If every adjacent pair satisfied the condition,
//             // add the number to the answer
//             if (possible) {
//                 result.push_back(i);
//             }
//         }

//         return result;
//     }
// };


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int> answer;

        // Base string containing all increasing digits
        string digits = "123456789";

        // Generate sequential numbers of every possible length
        for (int len = 2; len <= 9; len++) {

            // Generate every substring of the current length
            for (int start = 0; start <= 9 - len; start++) {

                // Extract substring
                string s = digits.substr(start, len);

                // Convert it into an integer
                int num = stoi(s);

                // Store it only if it lies in the required range
                if (num >= low && num <= high) {
                    answer.push_back(num);
                }
            }
        }

        return answer;
    }
};
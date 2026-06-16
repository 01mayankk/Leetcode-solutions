class Solution {
public:
    string processStr(string s) {
        // Stores the string being built after processing each character
        string result;

        // Process the input string from left to right
        for (char ch : s) {

            // If it is a lowercase letter, append it to result
            if (islower(ch)) {
                result += ch;
            }

            // '*' removes the last character from result (if any)
            else if (ch == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            }

            // '#' duplicates the current result and appends it to itself
            // Example: "ab" -> "abab"
            else if (ch == '#') {
                result += result;
            }

            // '%' reverses the current result
            // Example: "abcd" -> "dcba"
            else if (ch == '%') {
                reverse(result.begin(), result.end());
            }
        }

        // Return the final processed string
        return result;
    }
};
#include <string>
#include <climits>
#include <cctype>

class Solution {
public:
    int myAtoi(std::string s) {
        long long sign = 1, result = 0;
        int index = 0;
        int n = s.size();

        // Ignore leading whitespace
        while (index < n && s[index] == ' ') {
            index++;
        }

        // Determine the sign
        if (index < n && (s[index] == '-' || s[index] == '+')) {
            sign = (s[index] == '-') ? -1 : 1;
            index++;
        }

        // Convert digits to integer, handling overflow
        while (index < n && isdigit(s[index])) {
            int digit = s[index] - '0';

            // Check for overflow and underflow for 32-bit signed integer
            if (result > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            index++;
        }

        return static_cast<int>(result * sign);
    }
};
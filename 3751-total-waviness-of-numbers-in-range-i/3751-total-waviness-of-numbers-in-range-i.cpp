class Solution {
public:

    // Function to calculate waviness of a single number
    int getWaviness(int num) {

        // Convert number into string so that digits
        // can be accessed easily using indices
        string s = to_string(num);

        int n = s.size();

        // If number has less than 3 digits,
        // it cannot have any peak or valley
        if (n < 3)
            return 0;

        int waviness = 0;

        // Check every middle digit
        // First and last digits are ignored
        for (int i = 1; i < n - 1; i++) {

            char left  = s[i - 1];
            char mid   = s[i];
            char right = s[i + 1];

            // Peak Condition:
            // Current digit is greater than both neighbours
            if (mid > left && mid > right) {
                waviness++;
            }

            // Valley Condition:
            // Current digit is smaller than both neighbours
            else if (mid < left && mid < right) {
                waviness++;
            }
        }

        return waviness;
    }

    int totalWaviness(int num1, int num2) {

        int total = 0;

        // Visit every number in the range
        for (int num = num1; num <= num2; num++) {

            // Add waviness of current number
            total += getWaviness(num);
        }

        return total;
    }
};
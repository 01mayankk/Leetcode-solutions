class Solution
{
public:
    int maxDigitRange(vector<int> &nums)
    {
        int maximumDigitRange = -1;
        int answer = 0;

        // Traverse every number in the array.
        for (int number : nums)
        {
            int currentNumber = number;
            int minimumDigit = 9;
            int maximumDigit = 0;

            // Find the smallest and largest digit of the current number.
            while (currentNumber > 0)
            {
                int digit = currentNumber % 10;

                minimumDigit = min(minimumDigit, digit);
                maximumDigit = max(maximumDigit, digit);

                currentNumber /= 10;
            }

            // Calculate the digit range.
            int currentDigitRange = maximumDigit - minimumDigit;

            // Found a larger digit range.
            // Update the maximum range and reset the answer.
            if (currentDigitRange > maximumDigitRange)
            {
                maximumDigitRange = currentDigitRange;
                answer = number;
            }
            // Same maximum digit range.
            // Include this number in the final sum.
            else if (currentDigitRange == maximumDigitRange)
            {
                answer += number;
            }
        }

        return answer;
    }
};
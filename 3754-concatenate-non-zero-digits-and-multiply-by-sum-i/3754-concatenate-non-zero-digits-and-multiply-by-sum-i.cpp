class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        // Special case:
        // If the number is 0, there are no non-zero digits.
        if (n == 0)
        {
            return 0;
        }

        string number = to_string(n);

        long long concatenatedNumber = 0;
        long long digitSum = 0;

        // Traverse all digits in their original order.
        for (char ch : number)
        {
            // Ignore zero digits.
            if (ch == '0')
            {
                continue;
            }

            int digit = ch - '0';

            // Form the new number by concatenating non-zero digits.
            concatenatedNumber = concatenatedNumber * 10 + digit;

            // Add the digit to the sum.
            digitSum += digit;
        }

        // Return x * sum.
        return concatenatedNumber * digitSum;
    }
};
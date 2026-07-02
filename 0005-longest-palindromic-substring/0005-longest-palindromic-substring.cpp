class Solution
{
private:
    // Expands from the given left and right indices
    // and returns the length of the palindrome.
    int expandAroundCenter(string &s, int left, int right)
    {
        // Keep expanding while:
        // 1. Indices are within bounds.
        // 2. Characters at both ends are equal.
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }

        // We expand one step too far before the loop stops.
        // So, the actual palindrome length is:
        // (right - 1) - (left + 1) + 1
        // = right - left - 1
        return right - left - 1;
    }

public:
    string longestPalindrome(string s)
    {
        int n = s.size();

        // A string of length 0 or 1 is already a palindrome.
        if (n <= 1)
            return s;

        // Stores the starting index and maximum length
        // of the longest palindrome found so far.
        int start = 0;
        int maxLength = 1;

        // Consider every index as a possible center.
        for (int i = 0; i < n; i++)
        {
            // Case 1: Odd-length palindrome
            // Example: "aba"
            int oddLength = expandAroundCenter(s, i, i);

            // Case 2: Even-length palindrome
            // Example: "abba"
            int evenLength = expandAroundCenter(s, i, i + 1);

            // Take the larger palindrome.
            int currentLength = max(oddLength, evenLength);

            // Update answer if we found a longer palindrome.
            if (currentLength > maxLength)
            {
                maxLength = currentLength;

                // Calculate the starting index.
                // Example:
                // currentLength = 5, center = i
                // start = i - (5 - 1) / 2
                start = i - (currentLength - 1) / 2;
            }
        }

        // Return the longest palindromic substring.
        return s.substr(start, maxLength);
    }
};
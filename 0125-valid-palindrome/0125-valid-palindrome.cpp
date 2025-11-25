class Solution {
public:
    bool isPalindrome(string s) {
        
        string s1 = "";

        // Build a cleaned string containing only lowercase alphanumeric characters
        for(int i = 0; i < s.length(); i++)
        {
            // isalnum() checks if the character is A-Z, a-z, or 0-9
            if(isalnum((unsigned char)s[i]))
            {
                // convert to lowercase to ignore case differences
                s1 += tolower(s[i]);
            }
        }

        // Two-pointer technique to check palindrome
        int left = 0;
        int right = s1.length() - 1;

        while(left <= right)
        {
            // If mismatch, it's not a palindrome
            if(s1[left] != s1[right])
            {
                return false;
            }
            left++;
            right--;
        }

        // If all characters matched
        return true;
    }
};

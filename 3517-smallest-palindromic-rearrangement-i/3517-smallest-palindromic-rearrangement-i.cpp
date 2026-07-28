class Solution {
public:
    string smallestPalindrome(string s) {
        // Count the frequency of each character in the string
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        string half = "";
        string mid = "";
        
        // Build the lexicographically smallest first half and identify the middle character (if any)
        for (int i = 0; i < 26; i++) {
            // If the character has an odd count, it will be placed in the middle
            if (count[i] % 2 != 0) {
                mid += (char)(i + 'a');
            }
            // Add exactly half of the character's count to the first half of the palindrome
            // Processing in alphabetical order (i = 0 to 25) ensures the result is lexicographically smallest
            half += string(count[i] / 2, (char)(i + 'a'));
        }
        
        // The second half is simply the reverse of the first half
        string rev_half = half;
        reverse(rev_half.begin(), rev_half.end());
        
        // Construct and return the final palindrome
        return half + mid + rev_half;
    }
};
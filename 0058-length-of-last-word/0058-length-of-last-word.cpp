class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.length() - 1;

        // Skip any trailing spaces at the end of the string
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count the characters of the last word until a space or start of string is reached
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};
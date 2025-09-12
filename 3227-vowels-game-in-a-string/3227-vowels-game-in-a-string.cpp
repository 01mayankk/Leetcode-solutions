class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || 
                ch == 'o' || ch == 'u');
    }

    bool doesAliceWin(string s) {
        for (char c : s) {
            if (isVowel(c)) {
                return true;  // Alice wins if any vowel exists
            }
        }
        return false;  // no vowels → Bob wins
    }
};

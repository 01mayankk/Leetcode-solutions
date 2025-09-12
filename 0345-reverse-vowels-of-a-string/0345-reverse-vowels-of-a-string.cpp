class Solution {
public:
    bool vowel(char ch) {
        ch = tolower(ch);  // normalize to lowercase
        return (ch == 'a' || ch == 'e' || ch == 'i' || 
                ch == 'o' || ch == 'u');
    }

    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // Move left until vowel found
            while (left < right && !vowel(s[left])) {
                left++;
            }
            // Move right until vowel found
            while (left < right && !vowel(s[right])) {
                right--;
            }

            // Swap vowels
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};

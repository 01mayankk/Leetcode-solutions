class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;

        // Step 1: Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Find first character with frequency 1
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] == 1) {
                return i; // return the index
            }
        }

        // Step 3: If no unique character found
        return -1;
    }
};

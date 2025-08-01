class Solution {
public:
    bool isAnagram(string s, string t) {
        // Step 1: Sort both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // Step 2: If lengths are different, they can't be anagrams
        if (s.size() != t.size()) {
            return false;
        }

        // Step 3: Compare each character in the sorted strings
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                return false; // Characters don't match → not an anagram
            }
        }

        // Step 4: All characters matched → it's an anagram
        return true;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int i = 0; // pointer for string s (short string)
        int j = 0; // pointer for string t (long string)

        // Traverse both strings
        while (i < s.size() && j < t.size())
        {
            // If characters match, move pointer i
            if (s[i] == t[j])
            {
                i++;
            }

            // Always move pointer j
            j++;
        }

        // If we have matched all characters of s
        return i == s.size();
    }
};

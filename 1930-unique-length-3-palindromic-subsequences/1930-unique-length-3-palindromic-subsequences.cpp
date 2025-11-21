class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        // first[i] = first occurrence index of character 'a' + i
        // last[i]  = last  occurrence index of character 'a' + i
        //
        // We use only 26 slots because we are dealing with lowercase english letters.
        vector<int> first(26, -1), last(26, -1);

        // Step 1: Record the FIRST and LAST occurrence of every character.
        // This allows us to fix the outer characters of the palindrome "c _ c".
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) 
                first[c] = i;     // first time we see this character
            last[c] = i;           // keep updating to get the last index
        }

        int result = 0;

        // Step 2: For each character c from 'a' to 'z'
        // treat that character as the outer two characters of the palindrome: c _ c
        for (int c = 0; c < 26; c++) {

            // If a character occurs 0 or 1 time → cannot form "c _ c"
            if (first[c] == -1 || last[c] == -1 || first[c] == last[c])
                continue;

            int L = first[c];   // first occurrence
            int R = last[c];    // last occurrence

            // Step 3: We want to count DISTINCT characters that appear between L and R.
            //
            // Any such distinct character X gives a unique palindrome: c X c.
            vector<bool> middle(26, false);

            // Scan the substring (L+1 ... R-1)
            for (int i = L + 1; i < R; i++) {
                middle[s[i] - 'a'] = true;   // mark this character as present
            }

            // Step 4: Count how many distinct middle characters we found.
            for (int m = 0; m < 26; m++) {
                if (middle[m])
                    result++;
            }
        }

        // Final result = sum of all unique palindromic subsequences of length 3
        return result;
    }
};

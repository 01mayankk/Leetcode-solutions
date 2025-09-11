class Solution {
public:
    string sortVowels(string s) {
        // Step 1: Collect all vowels from the string 's'
        vector<char> vowels;
        for (char c : s) {
            // If the current character is a vowel, store it
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }

        // Step 2: Sort the collected vowels in ascending order (lexicographically)
        sort(vowels.begin(), vowels.end());

        // Step 3: Replace the vowels in the original string with the sorted vowels
        int v_index = 0;  // Index to track which sorted vowel to insert
        for (int i = 0; i < s.size(); i++) {
            // If current character is a vowel, replace it with the next sorted vowel
            if (isVowel(s[i])) {
                s[i] = vowels[v_index++];
            }
        }

        // Step 4: Return the modified string with vowels sorted
        return s;
    }

private:
    // Helper function to check if a given character is a vowel
    bool isVowel(char c) {
        // Check if 'c' exists in the string "AEIOUaeiou"
        // If found, it's a vowel; otherwise, it's not
        return string("AEIOUaeiou").find(c) != string::npos;
    }
};

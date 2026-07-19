class Solution {
public:
    string smallestSubsequence(string s) {
        // Store the last occurrence index of each character
        vector<int> lastIdx(26, 0);
        for (int i = 0; i < s.length(); i++) {
            lastIdx[s[i] - 'a'] = i;
        }
        
        // Track whether a character is already included in the result sequence
        vector<bool> seen(26, false);
        string result = "";
        
        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];
            
            // If the character is already taken, skip it
            if (seen[curr - 'a']) {
                continue;
            }
            
            // Maintain a monotonic character sequence:
            // Remove the last character from the result if it is lexicographically larger than the current character
            // AND it appears later in the string (so it can be safely picked up later).
            while (!result.empty() && result.back() > curr && lastIdx[result.back() - 'a'] > i) {
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            // Add the current character to the sequence and mark it as seen
            result.push_back(curr);
            seen[curr - 'a'] = true;
        }
        
        return result;
    }
};
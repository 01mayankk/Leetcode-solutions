class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> s;
        // Tracks lowercase characters that have already been counted as "special"
        vector<bool> counted(26, false); 
        int count = 0;
        
        for (char ch : word) {
            if (islower(ch)) {
                char upperVersion = toupper(ch);
                // If we found its uppercase partner and haven't counted this letter yet
                if (s.find(upperVersion) != s.end() && !counted[ch - 'a']) {
                    count++;
                    counted[ch - 'a'] = true;
                }
            } else if (isupper(ch)) {
                char lowerVersion = tolower(ch);
                // If we found its lowercase partner and haven't counted this letter yet
                if (s.find(lowerVersion) != s.end() && !counted[lowerVersion - 'a']) {
                    count++;
                    counted[lowerVersion - 'a'] = true;
                }
            }
            
            s.insert(ch);
        }
        
        return count;
    }
};
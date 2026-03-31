class Solution {
public:
    string generateString(string str1, string str2) {
        
        int n = str1.size();
        int m = str2.size();
        
        // Final length of generated string
        int len = n + m - 1;
        
        // Step 1: Initialize result with '?' (means not yet decided)
        vector<char> word(len, '?');
        
        // Step 2: Apply all 'T' constraints
        // For every i where str1[i] == 'T', we must place str2 starting at i
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T') {
                
                for(int j = 0; j < m; j++) {
                    
                    // If already filled and conflict occurs → impossible
                    if(word[i + j] != '?' && word[i + j] != str2[j]) {
                        return "";
                    }
                    
                    // Otherwise, fix the character
                    word[i + j] = str2[j];
                }
            }
        }
        
        // Step 3: Fill remaining '?' with 'a' to make lexicographically smallest string
        for(int i = 0; i < len; i++) {
            if(word[i] == '?') word[i] = 'a';
        }
        
        // Step 4: Handle 'F' constraints
        // For every i where str1[i] == 'F', substring must NOT equal str2
        for(int i = 0; i < n; i++) {
            
            if(str1[i] == 'F') {
                
                // Check if current substring equals str2
                bool match = true;
                for(int j = 0; j < m; j++) {
                    if(word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }
                
                // If equal → we must break this match
                if(match) {
                    
                    bool broken = false;
                    
                    // Try modifying from right to left (greedy for minimal change)
                    for(int j = m - 1; j >= 0; j--) {
                        
                        int idx = i + j;
                        char original = word[idx];
                        
                        // Try replacing with smallest possible different character
                        for(char c = 'a'; c <= 'z'; c++) {
                            if(c != original) {
                                
                                // Temporarily assign new character
                                word[idx] = c;
                                
                                // Check if this breaks any 'T' constraint
                                bool valid = true;
                                
                                // Re-check all 'T' constraints
                                for(int k = 0; k < n; k++) {
                                    if(str1[k] == 'T') {
                                        for(int x = 0; x < m; x++) {
                                            if(word[k + x] != str2[x]) {
                                                valid = false;
                                                break;
                                            }
                                        }
                                        if(!valid) break;
                                    }
                                }
                                
                                // If valid, we successfully broke the 'F' match
                                if(valid) {
                                    broken = true;
                                    break;
                                }
                                
                                // Otherwise revert change
                                word[idx] = original;
                            }
                        }
                        
                        // If already fixed, stop further changes
                        if(broken) break;
                    }
                    
                    // If we couldn't break the match → impossible
                    if(!broken) return "";
                }
            }
        }
        
        // Convert vector to string and return
        return string(word.begin(), word.end());
    }
};
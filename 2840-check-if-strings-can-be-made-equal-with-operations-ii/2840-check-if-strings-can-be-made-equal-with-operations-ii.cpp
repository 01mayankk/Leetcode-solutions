class Solution {
public:
    bool checkStrings(string s1, string s2) {
        
        int n = s1.size();
        
        // Frequency arrays for even indices
        vector<int> even1(26, 0), even2(26, 0);
        
        // Frequency arrays for odd indices
        vector<int> odd1(26, 0), odd2(26, 0);
        
        // Traverse both strings
        for(int i = 0; i < n; i++) {
            
            if(i % 2 == 0) {
                even1[s1[i] - 'a']++;
                even2[s2[i] - 'a']++;
            } else {
                odd1[s1[i] - 'a']++;
                odd2[s2[i] - 'a']++;
            }
        }
        
        // Compare both frequency groups
        return (even1 == even2) && (odd1 == odd2);
    }
};
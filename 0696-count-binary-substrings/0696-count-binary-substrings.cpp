class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int prevCount = 0;   // Length of previous group
        int currCount = 1;   // Length of current group
        int result = 0;
        
        // Start from index 1 since we compare with previous character
        for(int i = 1; i < s.length(); i++) {
            
            if(s[i] == s[i - 1]) {
                // Same character → increase current group length
                currCount++;
            } else {
                // Group changed
                
                // Add minimum of previous and current group
                result += min(prevCount, currCount);
                
                // Update previous group
                prevCount = currCount;
                
                // Reset current group
                currCount = 1;
            }
        }
        
        // Add last pair
        result += min(prevCount, currCount);
        
        return result;
    }
};
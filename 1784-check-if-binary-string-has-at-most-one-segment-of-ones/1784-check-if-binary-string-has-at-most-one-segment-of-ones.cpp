class Solution {
public:
    bool checkOnesSegment(string s) {
        
        // Flag to indicate that we have already finished the first segment of 1's
        bool zeroSeenAfterOne = false;
        
        // Traverse the string
        for(int i = 0; i < s.size(); i++)
        {
            // If we encounter '0', mark that zero appeared
            if(s[i] == '0')
            {
                zeroSeenAfterOne = true;
            }
            
            // If we see '1' after a zero appeared
            // it means another segment of 1s has started
            if(s[i] == '1' && zeroSeenAfterOne)
            {
                return false;
            }
        }
        
        // If no second segment found
        return true;
    }
};
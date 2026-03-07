class Solution {
public:
    int minFlips(string s) {
        
        int n = s.size();
        
        // Double the string to simulate all rotations
        string doubled = s + s;
        
        // Create two alternating patterns of length 2*n
        string alt1 = "", alt2 = "";
        
        for(int i = 0; i < 2 * n; i++)
        {
            // Pattern starting with '0' -> 010101...
            alt1 += (i % 2 == 0) ? '0' : '1';
            
            // Pattern starting with '1' -> 101010...
            alt2 += (i % 2 == 0) ? '1' : '0';
        }
        
        int res = INT_MAX;
        int diff1 = 0;   // mismatches with pattern1
        int diff2 = 0;   // mismatches with pattern2
        
        int left = 0;
        
        // Sliding window over doubled string
        for(int right = 0; right < 2 * n; right++)
        {
            // Count mismatches
            if(doubled[right] != alt1[right]) diff1++;
            if(doubled[right] != alt2[right]) diff2++;
            
            // Maintain window size = n
            if(right - left + 1 > n)
            {
                if(doubled[left] != alt1[left]) diff1--;
                if(doubled[left] != alt2[left]) diff2--;
                
                left++;
            }
            
            // When window size becomes exactly n
            if(right - left + 1 == n)
            {
                res = min(res, min(diff1, diff2));
            }
        }
        
        return res;
    }
};
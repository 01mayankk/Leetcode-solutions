class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        // Count of left moves, right moves, and flexible moves ('_')
        int L = 0, R = 0, blank = 0;
        
        // Step 1: Count how many 'L', 'R', and '_' are present
        for (char ch : moves) {
            if (ch == 'L') 
                L++;          // Move left
            else if (ch == 'R') 
                R++;          // Move right
            else 
                blank++;      // Flexible move ('_'), can be L or R
        }
        
        // Step 2: Try both extreme possibilities
        
        // Case 1: Convert all '_' into 'R' (maximize right movement)
        // Final position = (right moves + blanks) - left moves
        int goRight = R + blank - L;
        
        // Case 2: Convert all '_' into 'L' (maximize left movement)
        // Final position = (left moves + blanks) - right moves
        int goLeft = L + blank - R;
        
        // Step 3: Return the maximum distance from origin (absolute value)
        // We take absolute because distance can be left (-ve) or right (+ve)
        return max(abs(goRight), abs(goLeft));
    }
};
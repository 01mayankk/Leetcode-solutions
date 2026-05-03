class Solution {
public:
    bool rotateString(string s, string goal) {
        
        // Step 1: Length must be same
        if (s.length() != goal.length()) {
            return false;
        }

        // Step 2: Concatenate string with itself
        string doubled = s + s;

        // Step 3: Check if goal is substring of doubled string
        // If yes → goal is a rotation of s
        if (doubled.find(goal) != string::npos) {
            return true;
        }

        // Otherwise not a rotation
        return false;
    }
};
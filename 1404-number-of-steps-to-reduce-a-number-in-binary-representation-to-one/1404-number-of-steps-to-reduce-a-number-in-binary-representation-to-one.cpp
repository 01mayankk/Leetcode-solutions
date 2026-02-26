class Solution {
public:
    int numSteps(string s) {
        
        int steps = 0;
        int carry = 0;
        
        // Traverse from last bit to second bit
        // (skip first bit because we stop at "1")
        for(int i = s.size() - 1; i > 0; i--) {
            
            // Current bit after adding carry
            if((s[i] - '0' + carry) % 2 == 0) {
                // Even → divide by 2
                steps += 1;
            } else {
                // Odd → add 1 then divide
                steps += 2;
                carry = 1;   // generate carry
            }
        }
        
        // If carry remains at MSB
        return steps + carry;
    }
};
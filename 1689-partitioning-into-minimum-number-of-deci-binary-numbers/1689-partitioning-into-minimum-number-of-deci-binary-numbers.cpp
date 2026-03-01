class Solution {
public:
    int minPartitions(string n) {
        
        // Step 1: Store the maximum digit found
        int maxDigit = 0;
        
        // Step 2: Traverse each character in the string
        for(char ch : n) {
            
            // Convert character to integer digit
            int digit = ch - '0';
            
            // Update maximum digit
            maxDigit = max(maxDigit, digit);
            
            // Optimization: If we find '9', we can stop early
            // because 9 is the highest possible digit
            if(maxDigit == 9)
                return 9;
        }
        
        // Step 3: Return the maximum digit
        return maxDigit;
    }
};
class Solution {
public:
    // Function to check if a number is "good"
    bool isGood(int num) {
        // This flag ensures that after rotation,
        // the number becomes DIFFERENT (required condition)
        bool changed = false; 
        
        // Process each digit of the number
        while (num > 0) {
            int digit = num % 10;  // Extract last digit
            
            // ❌ If digit is invalid after rotation, number is NOT good
            if (digit == 3 || digit == 4 || digit == 7) {
                return false;
            }
            
            // ✅ If digit changes after rotation, mark flag
            // (2↔5 and 6↔9 cause change)
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                changed = true;
            }
            
            // Remove last digit
            num /= 10;
        }
        
        // Number is good ONLY if at least one digit caused change
        return changed; 
    }
    
    int rotatedDigits(int n) {
        int count = 0;  // Count of good numbers
        
        // Check every number from 1 to n
        for (int i = 1; i <= n; i++) {
            
            // If current number is good, increment count
            if (isGood(i)) {
                count++;
            }
        }
        
        // Return total good numbers
        return count;
    }
};
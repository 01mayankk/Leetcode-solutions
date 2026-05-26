class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        // Store lowercase letters
        unordered_set<char> lower;
        
        // Store uppercase letters
        unordered_set<char> upper;

        // Traverse the string
        for(char ch : word) {
            
            // If character is lowercase
            if(islower(ch)) {
                lower.insert(ch);
            }
            // If character is uppercase
            else {
                upper.insert(ch);
            }
        }

        int count = 0;

        // Check for every lowercase letter
        for(char ch : lower) {
            
            // Convert lowercase to uppercase
            char upperChar = toupper(ch);

            // If uppercase version exists
            if(upper.count(upperChar)) {
                count++;
            }
        }

        return count;
    }
};
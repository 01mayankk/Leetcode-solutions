class Solution {
public:
    
    int passwordStrength(string password) {
        
        // Set to store unique characters
        unordered_set<char> s;

        // Insert all characters into set
        // (duplicates will automatically be ignored)
        for(char ch : password)
        {
            s.insert(ch);
        }

        // Variable to store total strength score
        int sum = 0;

        // Traverse all unique characters
        for(auto& ch : s)
        {
            // If character is a digit (0-9)
            if(isdigit(ch))
            {
                sum += 3;
            }

            // If character is lowercase alphabet (a-z)
            else if(isalpha(ch) && ch >= 97 && ch <= 122)
            {
                sum += 1;
            }

            // If character is uppercase alphabet (A-Z)
            else if(isalpha(ch) && ch >= 65 && ch <= 90)
            {
                sum += 2;
            }

            // If character is a special symbol
            else if(ch == '!' || ch == '@' || ch == '#' || ch == '$')
            {
                sum += 5;
            }
        }

        // Return final password strength
        return sum;
    }
};
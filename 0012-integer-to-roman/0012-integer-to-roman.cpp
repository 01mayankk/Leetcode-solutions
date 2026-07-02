class Solution {
public:
    string intToRoman(int num) {
        // Map of Roman numeral values sorted in descending order
        const int romanValues[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        // Corresponding Roman numeral symbols (including subtractive cases like "CM", "CD", etc.)
        const string romanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result = "";
        
        // Iterate through each Roman numeral value/symbol pair
        for (int i = 0; i < 13; ++i) {
            // Append the symbol and subtract its value while the current number is large enough
            while (num >= romanValues[i]) {
                result += romanSymbols[i];
                num -= romanValues[i];
            }
        }
        
        return result;
    }
};
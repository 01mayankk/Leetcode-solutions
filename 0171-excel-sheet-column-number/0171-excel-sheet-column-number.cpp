class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int result = 0;
        int length = columnTitle.size();
        for(char ch : columnTitle)
        {
            result += ( ch - 64 )* pow(26, length - 1 );
            length--;
        }

        return result;
    }
};
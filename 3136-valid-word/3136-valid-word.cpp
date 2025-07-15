
class Solution {
public:
    bool isValid(string word) {
        
        int size = word.length();

        if(size < 3)
        {
            return false;
        }

        bool vowel = false;
        bool cons = false;
         transform(word.begin(), word.end(), word.begin(),::tolower);
        for(char ch : word)
        {
            if(!isalnum(ch))
            {
                return false;
            }
            else 
            {
               
               

                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                {
                    vowel = true;
                }
                else if(isdigit(ch))
                {
                    continue;
                }
                else
                {
                    cons = true;
                }
            }
        }

        if(vowel && cons)
        {
            return true;
        }

        return false;
    }
};
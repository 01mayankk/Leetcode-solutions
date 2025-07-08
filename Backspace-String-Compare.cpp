class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string s1, s2;

        for(char i : s)
        {
            if(i == '#' && !s1.empty())
            {
                s1.pop_back();
            }
            else
            {
                if(i == '#')
                {
                    continue;
                }
                s1.push_back(i);
            }
        }

        for(char j : t)
        {
            if(j == '#' && !s2.empty())
            {
                s2.pop_back();
            }
            else
            {
                if(j == '#')
                {
                    continue;
                }
                s2.push_back(j);
            }
        }

        if( s1 == s2)
        {
            return true;
        }

        return false;
    }
};
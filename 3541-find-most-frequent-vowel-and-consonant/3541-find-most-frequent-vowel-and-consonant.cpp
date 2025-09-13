class Solution {
public:
    bool isVowel(char ch)
    {
        ch = tolower(ch);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return true;
        }
        return false;
    }
    int maxFreqSum(string s) {
        
        unordered_map<char, int>vowels;
        unordered_map<char, int>consonant;
        int maxFreqV = 0;
        int maxFreqC = 0;
        for(char ch : s)
        {
            if(isVowel(ch))
            {
                vowels[ch]++;
            }else
            {
                consonant[ch]++;
            }
        }
        for (auto &p : vowels) {
            if (p.second > maxFreqV) {
                maxFreqV = p.second;
            }
        }
        
        for (auto &p : consonant) {
            if (p.second > maxFreqC) {
                maxFreqC = p.second;
            }
        }

        return maxFreqV + maxFreqC;
    }
};
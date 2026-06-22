class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        // Store the frequency of required characters
        unordered_map<char, int> mp;

        // Count occurrences of characters needed to form "balloon"
        for(char ch : text)
        {
            if(ch == 'b' || ch == 'a' || ch == 'l' || ch == 'o' || ch == 'n')
            {
                mp[ch]++;
            }
        }

        /*
            To form one "balloon", we need:
            b -> 1
            a -> 1
            l -> 2
            o -> 2
            n -> 1

            The character with the minimum available count
            determines how many complete "balloon" words
            can be formed.
        */
        int count = min({
            mp['b'],      // Number of 'b'
            mp['a'],      // Number of 'a'
            mp['l'] / 2,  // Two 'l's needed per balloon
            mp['o'] / 2,  // Two 'o's needed per balloon
            mp['n']       // Number of 'n'
        });

        return count;
    }
};
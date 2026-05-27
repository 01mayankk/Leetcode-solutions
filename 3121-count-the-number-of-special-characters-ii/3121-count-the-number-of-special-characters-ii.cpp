class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        int count = 0;

        // map to store LAST occurrence index
        // of every lowercase character
        unordered_map<char, int> mp;

        // first traversal
        // store last position of lowercase letters
        for(int i = 0; i < word.size(); i++)
        {
            char ch = word[i];

            // if character is lowercase
            if(islower(ch))
            {
                // update last occurrence
                mp[ch] = i;
            }
        }

        // set to avoid duplicate counting
        unordered_set<char> st;

        // second traversal
        // process uppercase characters
        for(int i = 0; i < word.size(); i++)
        {
            char ch = word[i];

            // check only uppercase letters
            if(isupper(ch))
            {
                // convert uppercase to lowercase
                char c = tolower(ch);

                /*
                    Conditions for special character:

                    1. lowercase character must exist
                    2. last lowercase occurrence must come
                       before FIRST uppercase occurrence
                    3. character should not already be counted
                */
                if(mp.find(c) != mp.end() &&
                   mp[c] < i &&
                   st.find(c) == st.end())
                {
                    count++;

                    // mark character as counted
                    st.insert(c);
                }

                /*
                    erase character after first uppercase
                    so later uppercase occurrences do not
                    incorrectly count the character
                */
                mp.erase(c);
            }
        }

        return count;
    }
};
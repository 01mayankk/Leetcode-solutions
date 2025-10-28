class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // If lengths differ, they can never be isomorphic
        if (s.size() != t.size()) return false;

        // Two hash maps for one-to-one mapping between characters
        unordered_map<char, char> map1; // maps characters from s -> t
        unordered_map<char, char> map2; // maps characters from t -> s

        // Traverse both strings simultaneously
        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i]; // current char from s
            char c2 = t[i]; // corresponding char from t

            // If c1 was already mapped before, check if it's consistent
            // e.g., if s[i] = 'a' was mapped to 'x' previously, 
            // then every future 'a' must map to 'x' again.
            if (map1.count(c1) && map1[c1] != c2)
                return false;

            // Similarly, ensure c2 (from t) isn’t already mapped to another char from s
            // This prevents two s-characters from mapping to the same t-character.
            if (map2.count(c2) && map2[c2] != c1)
                return false;

            // If no conflict, store the new mapping in both directions
            map1[c1] = c2;
            map2[c2] = c1;
        }

        // If no inconsistencies found, the strings are isomorphic
        return true;
    }
};

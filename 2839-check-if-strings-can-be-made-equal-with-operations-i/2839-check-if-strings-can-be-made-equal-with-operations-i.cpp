class Solution {
public:
    bool canBeEqual(string s1, string s2) {

        // We can swap characters at indices i and i+2
        // So effectively:
        // Even indices (0,2) form one group
        // Odd indices (1,3) form another group

        // Extract even and odd indexed characters
        vector<char> even1, odd1, even2, odd2;

        for(int i = 0; i < 4; i++) {
            if(i % 2 == 0) {
                even1.push_back(s1[i]); // s1 even positions
                even2.push_back(s2[i]); // s2 even positions
            } else {
                odd1.push_back(s1[i]);  // s1 odd positions
                odd2.push_back(s2[i]);  // s2 odd positions
            }
        }

        // Sort both groups (because we can rearrange freely within group)
        sort(even1.begin(), even1.end());
        sort(even2.begin(), even2.end());

        sort(odd1.begin(), odd1.end());
        sort(odd2.begin(), odd2.end());

        // If both even groups match AND both odd groups match → possible
        return (even1 == even2) && (odd1 == odd2);
    }
};
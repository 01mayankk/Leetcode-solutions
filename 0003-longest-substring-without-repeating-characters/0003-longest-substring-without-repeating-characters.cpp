class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> unique;
        int left = 0, right = 0;
        int maxLen = 0;

        while (right < s.length()) {
            if (unique.find(s[right]) == unique.end()) {
                unique.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
                right++;
            } else {
                unique.erase(s[left]);
                left++;
            }
        }

        return maxLen;
    }
};

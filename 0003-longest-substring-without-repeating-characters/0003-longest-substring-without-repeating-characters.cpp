class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // Stores characters currently present in the window
        unordered_set<char> unique;

        // Two pointers for Sliding Window
        int left = 0;
        int right = 0;

        // Stores length of longest substring without repeating characters
        int maxLen = 0;

        // Expand the window using right pointer
        while (right < s.length()) {

            // If current character is not present in the window
            if (unique.find(s[right]) == unique.end()) {

                // Add current character to the set
                unique.insert(s[right]);

                // Update maximum length found so far
                maxLen = max(maxLen, right - left + 1);

                // Expand window
                right++;
            }
            else {

                // Duplicate character found
                // Remove characters from left side
                // until duplicate is removed
                unique.erase(s[left]);
                left++;
            }
        }

        return maxLen;
    }
};
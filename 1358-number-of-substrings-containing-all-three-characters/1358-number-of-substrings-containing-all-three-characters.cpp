class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int freq[3] = {0};   // freq[0] -> 'a', freq[1] -> 'b', freq[2] -> 'c'
        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            // Include current character in the window
            freq[s[right] - 'a']++;

            // Shrink the window while it contains all three characters
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {

                // Every substring starting at 'left' and ending
                // from 'right' to 'n-1' is valid.
                ans += (n - right);

                // Remove the leftmost character
                freq[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};
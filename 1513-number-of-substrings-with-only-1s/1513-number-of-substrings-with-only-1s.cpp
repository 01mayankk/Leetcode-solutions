class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1e9 + 7;

        long long count1 = 0;   // counts length of the current continuous '1' segment
        long long ans = 0;      // stores total number of valid substrings

        for (char c : s) {

            if (c == '1') {
                // If character is '1', extend the current segment of consecutive '1's
                count1++;
            } else {
                // If we hit a '0':
                // For a segment of length k, total substrings = k * (k+1) / 2
                ans = (ans + (count1 * (count1 + 1) / 2) % MOD) % MOD;

                // Reset count of '1's since segment ends here
                count1 = 0;
            }
        }

        // After loop ends, add substrings from the last segment of '1's (if present)
        ans = (ans + (count1 * (count1 + 1) / 2) % MOD) % MOD;

        return ans;
    }
};

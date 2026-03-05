class Solution {
public:
    int minOperations(string s) {

        int n = s.length();

        // Count flips required if the alternating pattern starts with '0'
        // Pattern: 0 1 0 1 0 1 ...
        int startWithZero = 0;

        // Count flips required if the alternating pattern starts with '1'
        // Pattern: 1 0 1 0 1 0 ...
        int startWithOne = 0;

        for(int i = 0; i < n; i++)
        {
            // Determine expected characters for both patterns at index i
            char expectedIfZeroStart = (i % 2 == 0) ? '0' : '1';
            char expectedIfOneStart  = (i % 2 == 0) ? '1' : '0';

            // If current character does not match expected character
            // for the pattern starting with '0', a flip is required
            if(s[i] != expectedIfZeroStart)
                startWithZero++;

            // If current character does not match expected character
            // for the pattern starting with '1', a flip is required
            if(s[i] != expectedIfOneStart)
                startWithOne++;
        }

        // Minimum operations will be the minimum flips needed
        // between the two possible alternating patterns
        return min(startWithZero, startWithOne);
    }
};
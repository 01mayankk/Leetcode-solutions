class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {

        // Mod value for large answers
        const int MOD = 1e9 + 7;

        /*
        dp[i][j][0] = number of stable arrays using
                     i zeros and j ones and ending with 0

        dp[i][j][1] = number of stable arrays using
                     i zeros and j ones and ending with 1
        */

        vector<vector<array<long,2>>> dp(
            zero+1, vector<array<long,2>>(one+1, {0LL,0LL}));


        /*
        Base Case 1:
        If we only place zeros (no ones), the array is valid
        only if number of consecutive zeros ≤ limit.
        */

        for (int i = 1; i <= min(zero, limit); i++)
            dp[i][0][0] = 1;


        /*
        Base Case 2:
        If we only place ones (no zeros), the array is valid
        only if number of consecutive ones ≤ limit.
        */

        for (int j = 1; j <= min(one, limit); j++)
            dp[0][j][1] = 1;



        /*
        Fill DP table
        i = number of zeros used
        j = number of ones used
        */

        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {

                /*
                over0:
                If we append a 0 to a sequence that already has
                'limit' consecutive zeros, it becomes invalid.

                That invalid sequence originates from:
                dp[i-limit-1][j][1]

                Example (limit = 2):
                valid: 100
                invalid after append: 1000

                So we subtract those cases.
                */

                long over0 = (i-limit >= 1) ? dp[i-limit-1][j][1] : 0;


                /*
                over1:
                Similar logic for ones.
                If we append 1 to a sequence already having
                'limit' consecutive ones, it becomes invalid.
                */

                long over1 = (j-limit >= 1) ? dp[i][j-limit-1][0] : 0;



                /*
                Transition for ending with 0

                Normally we can append 0 to any sequence
                with (i-1 zeros, j ones):

                dp[i-1][j][0] -> continues zeros
                dp[i-1][j][1] -> switches from 1 to 0

                But we subtract sequences that would create
                more than 'limit' consecutive zeros.
                */

                dp[i][j][0] =
                    (dp[i-1][j][0] + dp[i-1][j][1] - over0 + MOD) % MOD;



                /*
                Transition for ending with 1

                Append 1 to sequences with (i zeros, j-1 ones)
                */

                dp[i][j][1] =
                    (dp[i][j-1][0] + dp[i][j-1][1] - over1 + MOD) % MOD;
            }
        }


        /*
        Final answer = arrays ending with 0 + arrays ending with 1
        using exactly 'zero' zeros and 'one' ones.
        */

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
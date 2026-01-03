class Solution {
public:
    int numOfWays(int n) {

        // Modulo constant as required by the problem
        const int MOD = 1e9 + 7;

        /*
            We classify row colorings into two types:

            1) aba pattern:
               - First and third cells have the same color
               - Middle cell has a different color
               Example: R G R
               Total ways for first row = 3 choices for R * 2 choices for G = 6

            2) abc pattern:
               - All three cells have different colors
               Example: R G B
               Total ways for first row = 3 * 2 * 1 = 6
        */
        long long aba = 6;
        long long abc = 6;

        /*
            Build the solution row by row from row 2 to row n.
            At each step we compute the new counts based on valid transitions.
        */
        for (int i = 2; i <= n; i++) {

            /*
                Transitions:
                - From previous 'aba':
                    -> 3 ways to form a new 'aba'
                    -> 2 ways to form a new 'abc'

                - From previous 'abc':
                    -> 2 ways to form a new 'aba'
                    -> 2 ways to form a new 'abc'
            */

            // New count of 'aba' patterns for current row
            long long newAba = (3 * aba + 2 * abc) % MOD;

            // New count of 'abc' patterns for current row
            long long newAbc = (2 * aba + 2 * abc) % MOD;

            // Update values for next iteration
            aba = newAba;
            abc = newAbc;
        }

        // Total valid ways = sum of both pattern types
        return (aba + abc) % MOD;
    }
};

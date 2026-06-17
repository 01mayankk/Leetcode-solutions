// class Solution {
// public:
//     char processStr(string s, long long k) {

//         string result;

//         for(char ch : s)
//         {
//             // Append lowercase letters
//             if(islower(ch))
//             {
//                 result += ch;
//             }

//             // Remove last character
//             else if(ch == '*')
//             {
//                 if(!result.empty())
//                 {
//                     result.pop_back();
//                 }
//             }

//             // Reverse current string
//             else if(ch == '%')
//             {
//                 reverse(result.begin(), result.end());
//             }

//             // Duplicate current string
//             else if(ch == '#')
//             {
//                 result += result;
//             }
//         }

//         // k is 0-based index
//         if(k >= result.size())
//         {
//             return '.';
//         }

//         return result[k];
//     }
// };

 /*
        Why the straightforward approach does NOT work:

        We can simulate the operations and build the final string using:

            result += ch
            result.pop_back()
            reverse(result.begin(), result.end())
            result += result

        However, the constraints allow the final string length to be as large
        as 10^15.

        Example:
            s = "a############################..."

        Every '#' doubles the current string length:

            1 -> 2 -> 4 -> 8 -> 16 -> ...

        After only ~50 '#' operations, the length exceeds 10^15.

        Therefore:

        1. We cannot actually construct the final string.
        2. Memory would be impossible (10^15 characters).
        3. reverse() and duplication operations would be extremely expensive.

        Instead, we only track lengths and work backwards from the required
        index k to determine which original character produced it.

        Time Complexity  : O(n)
        Space Complexity : O(n)
    */

class Solution {
public:

       char processStr(string s, long long k) {

        int n = s.size();

        // len[i] = length of the result after processing
        // the first i characters of s.
        vector<long long> len(n + 1, 0);

        // ----------------------------
        // Phase 1: Compute only lengths
        // ----------------------------
        for(int i = 0; i < n; i++)
        {
            char ch = s[i];

            // Append a lowercase character
            if(islower(ch))
            {
                len[i + 1] = len[i] + 1;
            }

            // Remove last character if present
            else if(ch == '*')
            {
                len[i + 1] = max(0LL, len[i] - 1);
            }

            // Duplicate the current string
            else if(ch == '#')
            {
                len[i + 1] = len[i] * 2;
            }

            // Reverse operation does not change length
            else // ch == '%'
            {
                len[i + 1] = len[i];
            }
        }

        // Final string length is len[n].
        // If k is outside the final string, answer is '.'
        if(k >= len[n])
        {
            return '.';
        }

        // -----------------------------------
        // Phase 2: Walk backwards through s
        // -----------------------------------
        for(int i = n - 1; i >= 0; i--)
        {
            char ch = s[i];

            // -------------------------------
            // Case 1: Lowercase letter
            // -------------------------------
            if(islower(ch))
            {
                long long oldLen = len[i];

                /*
                    Before appending:

                        length = oldLen

                    After appending:

                        length = oldLen + 1

                    The newly added character occupies index oldLen.

                    If k points exactly there, we found the answer.
                */
                if(k == oldLen)
                {
                    return ch;
                }

                // Otherwise k belonged to the previous string,
                // so nothing changes.
            }

            // -------------------------------
            // Case 2: '*'
            // -------------------------------
            else if(ch == '*')
            {
                /*
                    Forward:

                        abc -> ab

                    The last character was removed.

                    Since k is guaranteed to exist in the string AFTER
                    removal, its position remains unchanged when we move
                    back to the previous state.
                */
            }

            // -------------------------------
            // Case 3: '#'
            // -------------------------------
            else if(ch == '#')
            {
                long long oldLen = len[i];

                /*
                    Forward:

                        abc -> abcabc

                    If old length = L

                        index range [0, L-1]
                        index range [L, 2L-1]

                    Both halves are identical.

                    Map k back into the first half.
                */
                if(oldLen > 0)
                {
                    k %= oldLen;
                }
            }

            // -------------------------------
            // Case 4: '%'
            // -------------------------------
            else if(ch == '%')
            {
                long long L = len[i];

                /*
                    Forward:

                        abcde -> edcba

                    Index mapping:

                        newIndex = L - 1 - oldIndex

                    Therefore while moving backward:

                        oldIndex = L - 1 - newIndex
                */
                if(L > 0)
                {
                    k = L - 1 - k;
                }
            }
        }

        return '.';
    }
};
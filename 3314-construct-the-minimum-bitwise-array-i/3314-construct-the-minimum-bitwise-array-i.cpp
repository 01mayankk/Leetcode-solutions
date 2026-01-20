class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        // Initialize answer array with -1
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {

            // Special case:
            // Prime number 2 has no x such that x | (x + 1) = 2
            if (nums[i] == 2) {
                continue;
            }

            int val = nums[i];
            int pos = 0;

            /*
                Step 1:
                Count consecutive trailing 1s in binary representation.

                Example:
                val = 101111
                         ↑↑↑↑   => pos = 4
            */
            while (((val >> pos) & 1) == 1) {
                pos++;
            }

            /*
                Step 2:
                Two cases arise based on trailing ones
            */

            // Case 1: All bits are 1 (e.g., 1, 3, 7, 15)
            if ((1 << pos) > val) {

                /*
                    Remove the most significant bit (MSB)
                    This ensures x + 1 flips all bits below MSB
                    and x | (x + 1) reconstructs val
                */
                int msb = 31 - __builtin_clz(val);
                val = val & ~(1 << msb);

            }
            // Case 2: A zero bit exists after trailing ones
            else {

                /*
                    Clear the last 1 before the zero.
                    This guarantees correct carry propagation
                    when x + 1 is applied.
                */
                val = val & ~(1 << (pos - 1));
            }

            ans[i] = val;
        }

        return ans;
    }
};

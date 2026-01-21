class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;   // Stores the minimum valid y for each nums[i]

        for (int n : nums) {

            // Special case:
            // There is NO non-negative y such that:
            // y | (y + 1) == 2
            if (n == 2) {
                result.push_back(-1);
                continue;
            }

            /*
                Key Observation:
                ----------------
                To find the MINIMUM y such that:
                    y | (y + 1) == n

                We need to clear the lowest possible bit in n
                without breaking the OR condition.

                Let:
                    lowestSetBit = (n + 1) & (-(n + 1))

                This gives the lowest set bit of (n + 1).
                Dividing it by 2 gives the amount we can safely subtract
                from n to obtain the minimum valid y.
            */

            int lowestSetBitOfNext = (n + 1) & (-(n + 1));

            // Minimum y that satisfies y | (y + 1) == n
            int y = n - (lowestSetBitOfNext / 2);

            result.push_back(y);
        }

        return result;
    }
};

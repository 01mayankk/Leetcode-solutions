const int mod = 1e9 + 7;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int M = 100001;   // max possible value in nums (given by constraints)
        int n = nums.size();

        int freq[M] = {0};      // freq[v] = count of value 'v' in entire nums[]
        int prev[M] = {0};      // prev[v] = count of value 'v' seen so far on the left side

        // Count total frequency of each value
        for (int x : nums) freq[x]++;

        long long cnt = 0;

        // The first element is initially in the "left part"
        prev[nums[0]]++;

        // -----------------------------------------------------------
        // We consider nums[i] as the MIDDLE element of the triplet:
        // 
        // We want triplets (i, j, k) such that:
        //      nums[j] = x
        //      nums[i] = 2*x
        //      nums[k] = 2*x
        //
        // Therefore, for each middle x:
        //      left side must contain value (2*x)
        //      right side must contain value (2*x)
        //
        // Left count = prev[2*x]
        // Right count = freq[2*x] - prev[2*x] - (nums[i] == 0 ? 1 : 0)
        // -----------------------------------------------------------

        for (int i = 1; i < n - 1; i++) {

            const int x = nums[i];
            const int x2 = x << 1;   // x2 = 2*x

            // Only check 2*x if it fits within array bounds
            if (x2 < M) {

                // Count how many times 2*x has appeared on the LEFT side
                long long leftCount = prev[x2];

                // Count how many times 2*x appears on the RIGHT side
                long long rightCount = freq[x2] - prev[x2];

                // Adjustment when x == 0:
                // If x == 0, then x2 == 0, and nums[i] itself contributes once in freq[x2].
                // But nums[i] is the MIDDLE element, not allowed in left/right groups.
                // So subtract 1.
                if (x == 0)
                    rightCount--;

                // Add all valid combinations for this middle element x
                cnt += leftCount * rightCount;
            }

            // Move this value nums[i] to the "left part" for the next iteration
            prev[x]++;
        }

        return cnt % mod;
    }
};

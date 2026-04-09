class Solution {
public:
    const int MOD = 1000000007;

    // Fast modular exponentiation (Binary Exponentiation)
    // Computes (base^exp) % MOD efficiently in O(log exp)
    long long modExp(long long base, long long exp) {
        if (exp == 0) return 1;  // base case

        long long half = modExp(base, exp / 2);

        // square the half result
        long long result = (half * half) % MOD;

        // if exponent is odd, multiply one extra base
        if (exp % 2) result = (result * base) % MOD;

        return result;
    }

    int xorAfterQueries(vector<int>& arr, vector<vector<int>>& ops) {
        int len = arr.size();

        // Block size ~ sqrt(N) (used for sqrt decomposition optimization)
        int block = sqrt(len) + 1;

        // Buckets to group queries by step (k)
        // buckets[k] will store all queries having step = k
        vector<vector<vector<int>>> buckets(block);

        // STEP 1: Divide queries into two categories
        for (auto &query : ops) {
            int left = query[0];
            int right = query[1];
            int step = query[2];
            int val = query[3];

            if (step < block) {
                // Small step → defer processing using buckets
                buckets[step].push_back(query);
            } else {
                // Large step → directly apply updates (few iterations)
                for (int pos = left; pos <= right; pos += step) {
                    arr[pos] = (1LL * arr[pos] * val) % MOD;
                }
            }
        }

        // STEP 2: Process small step queries using prefix trick
        for (int step = 1; step < block; step++) {
            if (buckets[step].empty()) continue;

            // multiplier array to store effect of all queries
            // initialized with 1 (neutral element for multiplication)
            vector<long long> multiplier(len + step + 5, 1);

            for (auto &query : buckets[step]) {
                int left = query[0];
                int right = query[1];
                int val = query[3];

                // last valid index in this arithmetic progression
                int lastIndex = left + ((right - left) / step) * step;

                // stopping point (just beyond lastIndex)
                int stop = lastIndex + step;

                // Apply multiplication at start
                multiplier[left] = (multiplier[left] * val) % MOD;

                // Apply inverse at stop (to cancel effect after range)
                long long invVal = modExp(val, MOD - 2);
                multiplier[stop] = (multiplier[stop] * invVal) % MOD;
            }

            // STEP 3: Propagate multiplier along step chains
            // This simulates prefix multiplication but with step jumps
            for (int i = 0; i < len; i++) {
                if (i - step >= 0) {
                    multiplier[i] = (multiplier[i] * multiplier[i - step]) % MOD;
                }
            }

            // STEP 4: Apply computed multipliers to original array
            for (int i = 0; i < len; i++) {
                arr[i] = (1LL * arr[i] * multiplier[i]) % MOD;
            }
        }

        // STEP 5: Compute final XOR of all elements
        int ans = 0;
        for (int value : arr) {
            ans ^= value;
        }

        return ans;
    }
};
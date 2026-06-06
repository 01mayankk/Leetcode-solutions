using ll = long long;

class Solution {
    // Stores all 3-digit wave patterns
    // Example: 121, 232, 545, 989, 343 ...
    static inline int waves[570];

    // Precompute all valid wave patterns
    static inline bool init = []() {
        int idx = 0;

        for (int num = 0; num < 1000; num++) {
            int right = num % 10;
            int mid   = (num / 10) % 10;
            int left  = (num / 100) % 10;

            // Middle digit should be either
            // strictly greater than both neighbours (peak)
            // OR strictly smaller than both neighbours (valley)
            if ((mid > max(left, right)) ||
                (mid < min(left, right))) {
                waves[idx++] = num;
            }
        }

        return true;
    }();

public:
    ll totalWaviness(ll A, ll B) {
        // Count wave occurrences in [A, B]
        return waveCount(B) - waveCount(A - 1);
    }

private:

    // Counts total waviness from 1 to num
    ll waveCount(ll num) {
        if (num < 100)
            return 0;  // No 3-digit window exists

        return accumulate(begin(waves), end(waves), 0LL,
                          [&](ll ans, int pattern) {
                              return ans + countWays(num, pattern);
                          });
    }

    // Counts how many times a specific wave pattern
    // appears in all numbers from 0 to num
    ll countWays(ll num, int pattern) {

        // Pattern has leading zeros if < 100
        // Example: 012, 021 etc.
        ll leadingZeroAdjustment = (pattern < 100);

        ll count = 0;
        ll place = 1;

        // Process every 3-digit block position
        while (place * 100 <= num) {

            // Split number into:
            //
            // higher | current 3 digits | lower
            //
            // Example:
            // num = 1234567
            // place = 10
            //
            // higher = 123
            // current = 456
            // lower = 7

            ll higher  = num / (place * 1000);
            ll current = (num / place) % 1000;
            ll lower   = num % place;

            ll completeCycles = 0;

            if (current > pattern) {

                // Full contribution from all higher blocks
                completeCycles = higher - leadingZeroAdjustment + 1;

            } else if (current == pattern) {

                // Full cycles before current block
                completeCycles = max(0LL,
                                     higher - leadingZeroAdjustment);

                // Partial contribution from suffix
                count += lower + 1;

            } else {

                // Only completed higher cycles contribute
                completeCycles = max(0LL,
                                     higher - leadingZeroAdjustment);
            }

            // Every complete cycle contributes 'place' occurrences
            count += completeCycles * place;

            place *= 10;
        }

        return count;
    }
};
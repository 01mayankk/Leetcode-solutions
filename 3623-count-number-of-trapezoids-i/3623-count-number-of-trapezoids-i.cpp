class Solution {
public:
    static int countTrapezoids(vector<vector<int>>& points) {
        // We use modulo only for final answer (LeetCode requires mod 1e9+7)
        const long long mod = 1e9+7;
        const long long n = points.size();

        /************************************************************
         * Step 1: Count frequency of each y-level.
         * freq[y] = number of points having y-coordinate = y.
         *
         * A trapezoid requires:
         *   - choose 2 points on one y-level  (top base)
         *   - choose 2 points on another y-level (bottom base)
         ************************************************************/
        unordered_map<int, int> freq;
        freq.reserve(n);   // optimization: reduce rehashing

        for (auto &p : points)
            freq[p[1]]++;   // count points per y-level


        /************************************************************
         * We compute:
         *   c(y) = number of ways to choose 2 points on y-level
         *        = C(freq[y], 2) = freq[y]*(freq[y]-1)/2
         *
         * Let baseCounts = {c(y1), c(y2), ..., c(yk)} for all k y-levels.
         *
         * The number of trapezoids = sum_{i<j} ( c(yi) * c(yj) ).
         *
         * This is the same as:
         *   (sum c_i)^2 - sum (c_i^2)
         *   --------------------------------
         *                 2
         ************************************************************/

        long long sum = 0;  // sum of all c(y)
        long long c2  = 0;  // sum of c(y)^2

        for (auto &[y, f] : freq) {
            if (f <= 1) continue;  // cannot choose 2 points, skip

            // compute c = C(f,2)
            long long c = f * (f - 1LL) / 2LL;

            sum += c;      // accumulate sum of c(y)
            c2  += c * c;  // accumulate sum of c(y)^2
        }

        /************************************************************
         * Use combinatorial identity:
         *
         * Number of unordered pairs (i < j) = (sum^2 - sum_of_squares) / 2
         ************************************************************/
        long long ans = sum * sum - c2;

        ans /= 2;   // divide by 2 as per formula
        ans %= mod; // modulo

        return (int)ans;
    }
};

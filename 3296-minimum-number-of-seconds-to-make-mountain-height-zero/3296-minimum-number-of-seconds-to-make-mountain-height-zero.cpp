class Solution {
public:

    /*
        This function calculates the maximum height a single worker
        can reduce within a given amount of time.

        For a worker with time = workerTime:
        Time taken to reduce heights sequentially is:

        workerTime * (1 + 2 + 3 + ... + x)
        = workerTime * x * (x + 1) / 2

        We need the maximum x such that:
        workerTime * x * (x + 1) / 2 <= time

        Since x can be large, we use binary search to find it.
    */
    long long maxHeightReduced(long long time, int workerTime) {

        long long low = 0;
        long long high = 1e6;  // safe upper bound for height reduction

        while (low <= high) {

            long long mid = (low + high) / 2;

            // time required to reduce 'mid' units of height
            long long cost = 1LL * workerTime * mid * (mid + 1) / 2;

            if (cost <= time)
                // mid height is possible → try larger height
                low = mid + 1;
            else
                // too much time required → reduce height
                high = mid - 1;
        }

        // 'high' will be the largest valid height reduction
        return high;
    }


    /*
        Main function:
        We want to find the minimum number of seconds required
        to reduce the mountain height to zero.

        Approach: Binary Search on Answer

        Search space:
        Minimum time = 0
        Maximum time = very large (1e18)

        For each candidate time:
        - Calculate total height reduced by all workers.
        - If it is >= mountainHeight, time is sufficient.
        - Otherwise, we need more time.
    */
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long left = 0;
        long long right = 1e18;   // very large upper bound
        long long ans = right;

        while (left <= right) {

            long long mid = (left + right) / 2;

            long long totalReduced = 0;

            // Calculate total height reduced by all workers in 'mid' seconds
            for (int t : workerTimes) {

                totalReduced += maxHeightReduced(mid, t);

                // Early stop if we already reached required height
                if (totalReduced >= mountainHeight)
                    break;
            }

            // If workers can reduce enough height
            if (totalReduced >= mountainHeight) {
                ans = mid;          // store possible answer
                right = mid - 1;    // try to minimize time further
            }
            else {
                left = mid + 1;     // need more time
            }
        }

        return ans;
    }
};
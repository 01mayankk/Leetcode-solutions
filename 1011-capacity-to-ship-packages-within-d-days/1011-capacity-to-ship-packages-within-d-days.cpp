class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        // Minimum possible capacity:
        // At least the weight of the heaviest package (cannot split packages)
        int start = *max_element(weights.begin(), weights.end());

        // Maximum possible capacity:
        // Sum of all weights (shipping everything in one day)
        int end = accumulate(weights.begin(), weights.end(), 0);

        // Binary search on the answer (capacity)
        while (start < end) {

            // mid represents the candidate ship capacity
            int mid = start + (end - start) / 2;

            // Start with day 1
            int requiredDays = 1;

            // Current load on the ship for the ongoing day
            int load = 0;

            // Simulate shipping packages in order
            for (int w : weights) {

                // If adding this package exceeds capacity,
                // we need a new day
                if (load + w > mid) {
                    requiredDays++;   // move to next day
                    load = w;         // start new day with this package
                }
                // Otherwise, keep loading in the same day
                else {
                    load += w;
                }
            }

            // If we can ship within allowed days,
            // try reducing the capacity
            if (requiredDays <= days)
                end = mid;
            // Otherwise, capacity is too small → increase it
            else
                start = mid + 1;
        }

        // start (or end) now holds the minimum valid capacity
        return start;
    }
};

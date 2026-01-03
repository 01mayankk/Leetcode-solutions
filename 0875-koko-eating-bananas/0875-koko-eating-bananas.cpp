class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        // Minimum possible eating speed (bananas/hour)
        int low = 1;

        // Maximum possible eating speed
        // If Koko eats the largest pile in 1 hour
        int high = *max_element(piles.begin(), piles.end());

        // Binary search on the answer space [low, high]
        while (low < high) {

            // Try mid as current eating speed
            int mid = (low + high) / 2;

            // Total hours needed at speed = mid
            int hours = 0;

            // Calculate hours required for each pile
            for (int pile : piles) {
                // Ceiling division:
                // (pile + mid - 1) / mid
                // ensures partial bananas count as full hour
                hours += (pile + mid - 1) / mid;
            }

            // If Koko can finish within h hours
            if (hours <= h) {
                // Try smaller speed
                high = mid;
            } 
            else {
                // Need higher eating speed
                low = mid + 1;
            }
        }

        // low will be the minimum valid eating speed
        return low;
    }
};

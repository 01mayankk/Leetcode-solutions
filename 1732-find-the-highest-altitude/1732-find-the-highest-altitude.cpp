class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        // Current altitude of the biker.
        // Initially, the biker starts at altitude 0.
        int altitude = 0;

        // Stores the highest altitude reached so far.
        // Since we start at altitude 0, initialize it to 0.
        int maxAltitude = 0;

        // Traverse each gain/loss in altitude
        for (int g : gain) {

            // Update the current altitude
            altitude += g;

            // Update the maximum altitude if the current
            // altitude is greater than the previous maximum
            maxAltitude = max(maxAltitude, altitude);
        }

        // Return the highest altitude reached during the trip
        return maxAltitude;
    }
};
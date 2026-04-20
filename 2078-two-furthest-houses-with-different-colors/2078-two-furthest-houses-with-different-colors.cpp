class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDist = 0;

        // STEP 1:
        // Fix the first house (index 0) and try to find
        // the farthest house from the right having a different color
        for (int j = n - 1; j > 0; j--) {
            if (colors[0] != colors[j]) {
                // Distance between index 0 and j
                maxDist = j;  
                break; // This is the maximum possible from this side
            }
        }

        // STEP 2:
        // Fix the last house (index n-1) and try to find
        // the farthest house from the left having a different color
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] != colors[n - 1]) {
                // Distance between i and (n-1)
                maxDist = max(maxDist, (n - 1 - i));
                break; // Maximum possible from this side
            }
        }

        // Return the maximum distance found
        return maxDist;
    }
};
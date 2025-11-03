class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalCost = 0;                 // accumulate total removal time
        int n = colors.size();
        
        // Start from the second balloon and compare with the previous one
        for (int i = 1; i < n; i++) {
            // When two adjacent balloons have the same color,
            // we must remove one of them to avoid equal adjacent colors.
            if (colors[i] == colors[i - 1]) {
                // Remove the one with smaller removal time to minimize cost.
                if (neededTime[i] < neededTime[i - 1]) {
                    // Remove current balloon and add its cost
                    totalCost += neededTime[i];
                    // Important: set neededTime[i] to the larger time (the one we kept)
                    // so future comparisons use the surviving balloon's cost.
                    neededTime[i] = neededTime[i - 1];
                } else {
                    // Remove previous balloon and add its cost
                    totalCost += neededTime[i - 1];
                    // Do NOT change neededTime[i] — it already contains the larger (kept) time
                }
            }
        }
        return totalCost;
    }
};

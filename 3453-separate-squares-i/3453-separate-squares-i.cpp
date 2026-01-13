class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        // Total area of all squares
        double totalArea = 0.0;

        // Range for binary search on y
        double low = 1e18, high = 0.0;

        // Preprocess total area and bounds
        for (auto &sq : squares) {
            double y = sq[1];
            double l = sq[2];

            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double halfArea = totalArea / 2.0;

        // Binary search for minimum y such that
        // area below y >= halfArea
        for (int iter = 0; iter < 100; iter++) { 
            // 100 iterations are enough for 1e-5 precision
            double mid = (low + high) / 2.0;
            double areaBelow = 0.0;

            // Calculate area below the line y = mid
            for (auto &sq : squares) {
                double y = sq[1];
                double l = sq[2];

                if (mid <= y) {
                    // Entire square is above the line
                    continue;
                } else if (mid >= y + l) {
                    // Entire square is below the line
                    areaBelow += l * l;
                } else {
                    // Line cuts through the square
                    areaBelow += (mid - y) * l;
                }
            }

            // Adjust binary search
            if (areaBelow < halfArea) {
                low = mid;
            } else {
                high = mid;
            }
        }

        // 'low' is the minimum y satisfying the condition
        return low;
    }
};

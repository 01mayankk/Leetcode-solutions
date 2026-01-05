class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        long long totalSum = 0;      // Sum of absolute values
        int negCount = 0;            // Count of negative numbers
        int minAbs = INT_MAX;        // Minimum absolute value in matrix

        // Traverse the entire matrix
        for (auto &row : matrix) {
            for (int val : row) {

                // Add absolute value to total sum
                totalSum += abs(val);

                // Count negative numbers
                if (val < 0) {
                    negCount++;
                }

                // Track smallest absolute value
                minAbs = min(minAbs, abs(val));
            }
        }

        // If number of negatives is odd,
        // one number must stay negative → subtract twice minAbs
        if (negCount % 2 == 1) {
            totalSum -= 2LL * minAbs;
        }

        return totalSum;
    }
};

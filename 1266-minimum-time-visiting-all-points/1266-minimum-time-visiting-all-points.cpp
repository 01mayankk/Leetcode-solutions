class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {

        int totalTime = 0;

        // Iterate through consecutive points
        for (int i = 1; i < points.size(); i++) {

            // Difference in x and y coordinates
            int dx = abs(points[i][0] - points[i - 1][0]);
            int dy = abs(points[i][1] - points[i - 1][1]);

            // Minimum time needed is max(dx, dy)
            totalTime += max(dx, dy);
        }

        return totalTime;
    }
};

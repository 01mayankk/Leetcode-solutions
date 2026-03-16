class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        // n = number of rows, m = number of columns
        int n = grid.size(), m = grid[0].size();

        // set is used to store unique rhombus sums
        // it automatically keeps values sorted
        set<int> uniqueSum;

        // traverse every cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // rhombus of size 0 (just the cell itself)
                uniqueSum.insert(grid[i][j]);

                // try building larger rhombuses
                // len represents the "radius" of the rhombus
                for (int len = 1;
                     i + 2 * len < n && j - len >= 0 && j + len < m; len++) {

                    int currentSum = 0;

                    // edge 1: top → right
                    for (int ind = 0; ind < len; ind++)
                        currentSum += grid[i + ind][j + ind];

                    // edge 2: right → bottom
                    for (int ind = 0; ind < len; ind++)
                        currentSum += grid[i + len + ind][j + len - ind];

                    // edge 3: bottom → left
                    for (int ind = 0; ind < len; ind++)
                        currentSum += grid[i + 2 * len - ind][j - ind];

                    // edge 4: left → top
                    for (int ind = 0; ind < len; ind++)
                        currentSum += grid[i + len - ind][j - len + ind];

                    // store the rhombus border sum
                    uniqueSum.insert(currentSum);
                }
            }
        }

        // convert set into vector in descending order
        vector<int> ans(uniqueSum.rbegin(), uniqueSum.rend());

        // we only need the largest 3 values
        if (ans.size() > 3)
            ans.resize(3);

        return ans;
    }
};
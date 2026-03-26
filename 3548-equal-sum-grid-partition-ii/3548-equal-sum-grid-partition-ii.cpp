class Solution {
public:
    typedef long long ll;

    /*
    ------------------------------------------------------------
    Function: solve()
    Purpose:
        Checks whether we can partition the grid horizontally
        into two parts such that:
        1. Both parts have equal sum OR
        2. By removing exactly one element from either part,
           the sums can be made equal.
    ------------------------------------------------------------
    */
    bool solve(vector<vector<int>>& grid) {

        int n = grid.size();        // Number of rows
        int m = grid[0].size();     // Number of columns

        ll totalSum = 0;            // Sum of bottom part (initially full grid)
        ll topSum = 0;              // Sum of top part

        // Frequency arrays to quickly check if a value exists
        // in top or bottom partition (value range ≤ 100000)
        vector<int> bottomFreq(100001, 0), topFreq(100001, 0);

        /*
        ------------------------------------------------------------
        Step 1: Calculate total sum and initialize bottom frequency
        Initially, entire grid is considered as "bottom"
        ------------------------------------------------------------
        */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                totalSum += grid[i][j];
                bottomFreq[grid[i][j]]++;
            }
        }

        /*
        ------------------------------------------------------------
        Step 2: Try splitting after each row
        Move rows one by one from bottom → top
        ------------------------------------------------------------
        */
        for (int i = 0; i < n - 1; i++) {

            // Move current row into top partition
            for (int j = 0; j < m; j++) {
                totalSum -= grid[i][j];      // remove from bottom
                bottomFreq[grid[i][j]]--;

                topSum += grid[i][j];        // add to top
                topFreq[grid[i][j]]++;
            }

            /*
            ------------------------------------------------------------
            Case 1: Perfect partition (no removal needed)
            ------------------------------------------------------------
            */
            if (topSum == totalSum) return true;

            /*
            ------------------------------------------------------------
            Case 2: Try removing one element from TOP
            If topSum > bottomSum, we need to remove extra value
            ------------------------------------------------------------
            */
            ll diffTop = topSum - totalSum;

            if (diffTop > 0 && diffTop <= 100000) {
                int height = i + 1;   // height of top partition
                int width = m;

                if (height > 1 && width > 1) {
                    // General case: just check if value exists
                    if (topFreq[diffTop]) return true;
                } 
                else if (height > 1 && width == 1) {
                    // Single column → only edge elements matter
                    if (grid[0][0] == diffTop || grid[i][0] == diffTop)
                        return true;
                } 
                else if (height == 1 && width > 1) {
                    // Single row → only first/last element matters
                    if (grid[0][0] == diffTop || grid[0][width - 1] == diffTop)
                        return true;
                }
            }

            /*
            ------------------------------------------------------------
            Case 3: Try removing one element from BOTTOM
            If bottomSum > topSum, remove extra value
            ------------------------------------------------------------
            */
            ll diffBottom = totalSum - topSum;

            if (diffBottom > 0 && diffBottom <= 100000) {
                int height = n - i - 1;   // height of bottom partition
                int width = m;

                if (height > 1 && width > 1) {
                    // General case
                    if (bottomFreq[diffBottom]) return true;
                } 
                else if (height > 1 && width == 1) {
                    // Single column
                    if (grid[i + 1][0] == diffBottom || grid[n - 1][0] == diffBottom)
                        return true;
                } 
                else if (height == 1 && width > 1) {
                    // Single row
                    if (grid[n - 1][0] == diffBottom || grid[n - 1][width - 1] == diffBottom)
                        return true;
                }
            }
        }

        // No valid partition found
        return false;
    }

    /*
    ------------------------------------------------------------
    Function: canPartitionGrid()
    Purpose:
        Try both horizontal and vertical partitioning.

        Trick:
        Instead of writing separate logic for vertical split,
        we transpose the grid and reuse the same function.
    ------------------------------------------------------------
    */
    bool canPartitionGrid(vector<vector<int>>& grid) {

        // Try horizontal partition
        if (solve(grid)) return true;

        /*
        ------------------------------------------------------------
        Transpose the grid
        Rows ↔ Columns
        This converts vertical split into horizontal split
        ------------------------------------------------------------
        */
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> transposed(m, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                transposed[j][i] = grid[i][j];
            }
        }

        // Try vertical partition using same logic
        return solve(transposed);
    }
};
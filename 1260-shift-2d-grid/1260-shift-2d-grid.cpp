class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int rows = grid.size();
        int cols = grid[0].size();
        int total = rows * cols;

        // A full cycle brings the grid back to its original state,
        // so only the remaining shifts matter.
        k %= total;

        // Create the result grid with the same dimensions.
        vector<vector<int>> ans(rows, vector<int>(cols));

        // Traverse every element of the original grid.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                // Convert the current 2D position into a 1D index.
                // Example:
                // 1 2 3
                // 4 5 6   -> indices: 0 1 2 3 4 5 ...
                int currentIndex = i * cols + j;

                // Compute the new index after shifting k positions.
                // Modulo handles the wrap-around to the beginning.
                int newIndex = (currentIndex + k) % total;

                // Convert the new 1D index back into (row, col).
                int newRow = newIndex / cols;
                int newCol = newIndex % cols;

                // Place the current element into its new position.
                ans[newRow][newCol] = grid[i][j];
            }
        }

        // Return the shifted grid.
        return ans;
    }
};
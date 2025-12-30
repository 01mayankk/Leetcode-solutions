class Solution {
public:
    // Check if the 3x3 subgrid starting at (r, c) is a magic square
    bool isMagic(vector<vector<int>>& g, int r, int c) {

        // 👉 Optimization:
        // In every 3x3 magic square using numbers 1–9,
        // the center element MUST be 5
        if (g[r + 1][c + 1] != 5) return false;

        // used[i] → tracks whether number i (1–9) is already used
        vector<bool> used(10, false);

        // Validate:
        // 1. All numbers must be between 1 and 9
        // 2. Each number must appear only once
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int val = g[i][j];

                // Invalid number or duplicate
                if (val < 1 || val > 9 || used[val])
                    return false;

                used[val] = true;
            }
        }

        // Check all row sums and column sums
        // Each must equal 15
        for (int i = 0; i < 3; i++) {

            // Row sum
            if (g[r + i][c] + g[r + i][c + 1] + g[r + i][c + 2] != 15)
                return false;

            // Column sum
            if (g[r][c + i] + g[r + 1][c + i] + g[r + 2][c + i] != 15)
                return false;
        }

        // Check main diagonal sum
        if (g[r][c] + g[r + 1][c + 1] + g[r + 2][c + 2] != 15)
            return false;

        // Check secondary diagonal sum
        if (g[r][c + 2] + g[r + 1][c + 1] + g[r + 2][c] != 15)
            return false;

        // All conditions satisfied → valid magic square
        return true;
    }

    // Count number of 3x3 magic squares in the grid
    int numMagicSquaresInside(vector<vector<int>>& grid) {

        int n = grid.size();        // number of rows
        int m = grid[0].size();     // number of columns
        int count = 0;

        // Traverse all possible 3x3 subgrids
        for (int i = 0; i + 2 < n; i++) {
            for (int j = 0; j + 2 < m; j++) {

                // Check if current 3x3 subgrid is magic
                if (isMagic(grid, i, j))
                    count++;
            }
        }

        // Total number of magic squares found
        return count;
    }
};

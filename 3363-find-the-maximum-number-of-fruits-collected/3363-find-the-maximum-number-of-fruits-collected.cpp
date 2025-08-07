class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& grid) {
        int n = grid.size();  // Get the size of the grid (n x n)
        int res = 0;          // Variable to store the total maximum fruits collected

        // Step 1: Add all the fruits on the main diagonal (i.e., (0,0), (1,1), ..., (n-1,n-1))
        for (int i = 0; i < n; i++) {
            res += grid[i][i];
        }

        // Step 2: We perform the dynamic programming pass twice:
        //         First for the top-right to bottom-right path,
        //         Second for the top-left to bottom-left path by transposing the grid
        for (int pass = 0; pass < 2; pass++) {
            // If pass == 1, transpose the grid to handle the mirrored path
            if (pass == 1) {
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        swap(grid[i][j], grid[j][i]);
                    }
                }
            }

            // prev stores the max fruits collected at each column of the previous row
            // curr stores the same for the current row being processed
            vector<int> prev(n, -1), curr(n, -1);
            
            // Starting point: collect fruit at (0, n-1) — top-right corner
            prev[n - 1] = grid[0][n - 1];

            // Start from the second row and go till second-last (row 1 to n-2)
            for(int row = 1; row < n - 1; row++) {
                fill(curr.begin(), curr.end(), -1);  // Reset current row values to -1

                // Try to move from every possible column in the previous row
                for (int i = 0; i < n; i++) {
                    if (prev[i] < 0) continue;  // Skip if path to current cell is invalid

                    // Move left (i - 1)
                    if (i > 0) 
                        curr[i - 1] = max(curr[i - 1], prev[i] + grid[row][i - 1]);

                    // Move right (i + 1)
                    if (i < n - 1) 
                        curr[i + 1] = max(curr[i + 1], prev[i] + grid[row][i + 1]);

                    // Stay in the same column
                    curr[i] = max(curr[i], prev[i] + grid[row][i]);
                }

                // Move current row to previous for the next iteration
                swap(prev, curr);
            }

            // Finally, add the best path value at the bottom-right (or bottom-left if transposed)
            res += prev[n - 1];
        }

        return res;  // Return the total maximum fruits collected from all paths
    }
};

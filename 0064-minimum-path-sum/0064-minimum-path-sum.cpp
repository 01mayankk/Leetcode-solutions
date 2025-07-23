// class Solution {
// public:
//     int minPath(vector<vector<int>>& grid, int row, int col) {
//         // If out of bounds, return a very large number (invalid path)
//         if(row < 0 || col < 0) {
//             return INT_MAX;
//         }

//         // Base case: reached the starting cell
//         if(row == 0 && col == 0) {
//             return grid[0][0];
//         }

//         // Recursive calls: from top and left
//         int top = minPath(grid, row - 1, col);
//         int left = minPath(grid, row, col - 1);

//         return grid[row][col] + min(top, left);
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         int rowSize = grid.size();
//         int colSize = grid[0].size();

//         return minPath(grid, rowSize - 1, colSize - 1);
//     }
// };

//Above approach is just opposite direction as the questio is asked it go from down right to top left;

// class Solution {
// public:
//     int minPath(vector<vector<int>>& grid, int row, int col) {
//         int rowSize = grid.size();
//         int colSize = grid[0].size();

//         // If out of bounds, return large value (invalid path)
//         if(row >= rowSize || col >= colSize) {
//             return INT_MAX;
//         }

//         // Destination cell
//         if(row == rowSize - 1 && col == colSize - 1) {
//             return grid[row][col];
//         }

//         // Recursive calls: move right and down
//         int down = minPath(grid, row + 1, col);
//         int right = minPath(grid, row, col + 1);

//         return grid[row][col] + min(down, right);
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         return minPath(grid, 0, 0);
//     }
// };

//Here in this approach it is done using recursive appraoch in same direction as asked but it gives TLE due to some unnecessary computation which we have already calculated 



class Solution {
public:
    int minPath(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp) {
        // Out of bounds → invalid path
        if (row < 0 || col < 0) return INT_MAX;

        // Base case: starting point
        if (row == 0 && col == 0) return grid[0][0];

        // If already computed, return it
        if (dp[row][col] != -1) return dp[row][col];

        // Recursive calls
        int fromTop = minPath(grid, row - 1, col, dp);
        int fromLeft = minPath(grid, row, col - 1, dp);

        // Store and return result
        return dp[row][col] = grid[row][col] + min(fromTop, fromLeft);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();

        // Initialize dp with -1
        vector<vector<int>> dp(rowSize, vector<int>(colSize, -1));

        return minPath(grid, rowSize - 1, colSize - 1, dp);
    }
};


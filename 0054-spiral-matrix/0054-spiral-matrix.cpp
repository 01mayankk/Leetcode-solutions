class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();          // Number of rows in the matrix
        int n = matrix[0].size();       // Number of columns in the matrix

        // A 2D boolean array to keep track of visited cells
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        
        vector<int> result;  // To store the final spiral order traversal

        // Directions to move in spiral order:
        // Right → Down → Left → Up
        int dx[4] = {0, 1, 0, -1}; // Change in row index (x direction)
        int dy[4] = {1, 0, -1, 0}; // Change in column index (y direction)

        int x = 0, y = 0, dir = 0; // Start at top-left corner (0,0), facing "Right"

        // Traverse all elements in the matrix (m * n times)
        for (int i = 0; i < m * n; ++i) {
            result.push_back(matrix[x][y]); // Add the current element to result
            visited[x][y] = true;           // Mark the current cell as visited

            // Compute the next cell based on the current direction
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // Check if the next cell is invalid (out of bounds or already visited)
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) {
                // Change direction clockwise (Right → Down → Left → Up)
                dir = (dir + 1) % 4;

                // Recalculate the next position after changing direction
                nx = x + dx[dir];
                ny = y + dy[dir];
            }

            // Move to the next valid position
            x = nx;
            y = ny;
        }

        return result; // Return the spiral order traversal
    }
};

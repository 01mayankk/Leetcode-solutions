class Solution {
public:

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        // Rows and columns of matrix
        int m = grid.size();
        int n = grid[0].size();

        // Total number of layers (rings)
        // Example:
        // 4x4 matrix -> 2 layers
        int layers = min(m, n) / 2;

        // Traverse every layer one by one
        for (int layer = 0; layer < layers; layer++) {

            // Stores current layer elements
            vector<int> arr;

            // Boundaries of current layer
            int top = layer;
            int bottom = m - layer - 1;
            int left = layer;
            int right = n - layer - 1;

            // ======================================
            // STEP 1: Extract all layer elements
            // ======================================

            // Traverse top row (left -> right)
            for (int j = left; j <= right; j++) {
                arr.push_back(grid[top][j]);
            }

            // Traverse right column (top -> bottom)
            // Skip corners because already included
            for (int i = top + 1; i < bottom; i++) {
                arr.push_back(grid[i][right]);
            }

            // Traverse bottom row (right -> left)
            for (int j = right; j >= left; j--) {
                arr.push_back(grid[bottom][j]);
            }

            // Traverse left column (bottom -> top)
            // Skip corners because already included
            for (int i = bottom - 1; i > top; i--) {
                arr.push_back(grid[i][left]);
            }

            // ======================================
            // STEP 2: Rotate extracted array
            // ======================================

            // Total elements in current layer
            int len = arr.size();

            // Effective rotations
            // Avoid unnecessary full rotations
            int rotate = k % len;

            // Stores rotated elements
            vector<int> rotated(len);

            // Perform left rotation
            //
            // Example:
            // arr = [1,2,3,4]
            // k = 1
            // rotated = [2,3,4,1]
            for (int i = 0; i < len; i++) {
                rotated[i] = arr[(i + rotate) % len];
            }

            // ======================================
            // STEP 3: Put rotated values back
            // ======================================

            // Index for rotated array
            int idx = 0;

            // Fill top row
            for (int j = left; j <= right; j++) {
                grid[top][j] = rotated[idx++];
            }

            // Fill right column
            for (int i = top + 1; i < bottom; i++) {
                grid[i][right] = rotated[idx++];
            }

            // Fill bottom row
            for (int j = right; j >= left; j--) {
                grid[bottom][j] = rotated[idx++];
            }

            // Fill left column
            for (int i = bottom - 1; i > top; i--) {
                grid[i][left] = rotated[idx++];
            }
        }

        // Return final rotated matrix
        return grid;
    }
};
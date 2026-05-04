class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Get the size of the matrix (n x n)
        int n = matrix.size();
        
        // -------------------------------
        // STEP 1: TRANSPOSE THE MATRIX
        // -------------------------------
        // Transpose means converting rows into columns.
        // We swap matrix[i][j] with matrix[j][i]
        // Only traverse upper triangle to avoid double swapping
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Swap element at (i, j) with (j, i)
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // After transpose:
        // Example:
        // 1 2 3       1 4 7
        // 4 5 6  -->  2 5 8
        // 7 8 9       3 6 9
        
        
        // -------------------------------
        // STEP 2: REVERSE EACH ROW
        // -------------------------------
        // Reversing each row gives us the final rotated matrix
        
        for (int i = 0; i < n; i++) {
            // Reverse elements of row i
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
        // Final result after reversing rows:
        // 7 4 1
        // 8 5 2
        // 9 6 3
    }
};
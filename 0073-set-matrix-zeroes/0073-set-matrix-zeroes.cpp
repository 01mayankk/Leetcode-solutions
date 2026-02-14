class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        // Number of rows in matrix
        int rows = matrix.size();
        
        // Number of columns in matrix
        int cols = matrix[0].size();
        
        // zeroRow[i] = true  → means row i must be turned into all zeros
        vector<bool> zeroRow(rows, false);
        
        // zeroCol[j] = true → means column j must be turned into all zeros
        vector<bool> zeroCol(cols, false);
        
        // -------------------------
        // STEP 1: Identify rows and columns that contain at least one zero
        // -------------------------
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                
                // If we find a zero element
                if(matrix[i][j] == 0) {
                    
                    // Mark entire row i to become zero
                    zeroRow[i] = true;
                    
                    // Mark entire column j to become zero
                    zeroCol[j] = true;
                }
            }
        }
        
        // -------------------------
        // STEP 2: Traverse again and set elements to zero
        // -------------------------
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                
                // If this row OR column was marked
                // then this cell must be zero
                if(zeroRow[i] || zeroCol[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

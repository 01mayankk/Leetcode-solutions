class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();       // number of rows
        int m = mat[0].size();    // number of columns
        
        // Traverse each row
        for (int i = 0; i < n; i++) {
            // Traverse each column
            for (int j = 0; j < m; j++) {
                
                // Calculate new position after k shifts
                int newCol;
                
                if (i % 2 == 0) {
                    // Even row → left shift
                    newCol = (j + k) % m;
                } else {
                    // Odd row → right shift
                    newCol = (j - k % m + m) % m;
                }
                
                // Check if value matches original matrix
                if (mat[i][j] != mat[i][newCol]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
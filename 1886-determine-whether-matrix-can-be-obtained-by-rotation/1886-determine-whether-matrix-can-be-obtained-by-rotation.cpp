class Solution {
public:
    
    // Function to rotate matrix 90 degree clockwise (in-place)
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // Step 1: Transpose the matrix
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        // Step 2: Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        // Try all 4 rotations (0°, 90°, 180°, 270°)
        for(int k = 0; k < 4; k++) {
            
            // If matrices match → return true
            if(mat == target) return true;
            
            // Rotate matrix by 90 degrees
            rotate(mat);
        }
        
        // If no rotation matched
        return false;
    }
};
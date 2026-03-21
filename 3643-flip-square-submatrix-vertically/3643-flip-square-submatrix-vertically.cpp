class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        // We will swap rows inside the k x k submatrix
        // Only need to go till half (like reversing an array)
        for (int i = 0; i < k / 2; i++) {
            
            // Top row index inside submatrix
            int topRow = x + i;
            
            // Bottom row index inside submatrix
            int bottomRow = x + k - 1 - i;
            
            // Swap elements column-wise within the submatrix
            for (int j = 0; j < k; j++) {
                
                int col = y + j; // actual column index
                
                // Swap grid[topRow][col] with grid[bottomRow][col]
                swap(grid[topRow][col], grid[bottomRow][col]);
            }
        }
        
        return grid; // return updated grid
    }
};
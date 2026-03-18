// class Solution {//  This is passing all the test but it can be more optimized in terms of space.
// public:
//     int countSubmatrices(vector<vector<int>>& grid, int k) {
//         // Get dimensions of the grid
//         int n = grid.size();
//         int m = grid[0].size();
        
//         // Prefix sum matrix to store sum from (0,0) to (i,j)
//         vector<vector<long long>> prefix(n, vector<long long>(m, 0));
        
//         int count = 0; // To store number of valid submatrices
        
//         // Traverse each cell
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
                
//                 // Start with current cell value
//                 prefix[i][j] = grid[i][j];
                
//                 // Add sum from the cell above (if exists)
//                 if (i > 0)
//                     prefix[i][j] += prefix[i - 1][j];
                
//                 // Add sum from the left cell (if exists)
//                 if (j > 0)
//                     prefix[i][j] += prefix[i][j - 1];
                
//                 // Subtract the overlapping top-left part 
//                 // (because it was added twice)
//                 if (i > 0 && j > 0)
//                     prefix[i][j] -= prefix[i - 1][j - 1];
                
//                 /*
//                     Now prefix[i][j] represents the sum of submatrix
//                     from (0,0) to (i,j)
                    
//                     If this sum is <= k, it is a valid submatrix
//                 */
//                 if (prefix[i][j] <= k)
//                     count++;
//             }
//         }
        
//         // Return total count of valid submatrices
//         return count;
//     }
// };

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        // Get dimensions of the grid
        int n = grid.size();
        int m = grid[0].size();
        
        int count = 0; // Stores number of valid submatrices
        
        // Traverse each cell of the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                /*
                    Convert grid into prefix sum matrix IN-PLACE
                    
                    grid[i][j] will store sum of submatrix:
                    from (0,0) to (i,j)
                */
                
                // Add value from top cell (if exists)
                if (i > 0)
                    grid[i][j] += grid[i - 1][j];
                
                // Add value from left cell (if exists)
                if (j > 0)
                    grid[i][j] += grid[i][j - 1];
                
                // Subtract top-left overlap (to avoid double counting)
                if (i > 0 && j > 0)
                    grid[i][j] -= grid[i - 1][j - 1];
                
                /*
                    Now grid[i][j] represents sum of submatrix
                    from (0,0) → (i,j)
                    
                    If this sum is <= k, it is a valid submatrix
                */
                if (grid[i][j] <= k)
                    count++;
            }
        }
        
        // Return total count of valid submatrices
        return count;
    }
};
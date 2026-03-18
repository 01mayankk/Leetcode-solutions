class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Create prefix sum matrix
        vector<vector<long long>> prefix(n, vector<long long>(m, 0));
        
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                // Current cell value
                prefix[i][j] = grid[i][j];
                
                // Add top
                if (i > 0)
                    prefix[i][j] += prefix[i - 1][j];
                
                // Add left
                if (j > 0)
                    prefix[i][j] += prefix[i][j - 1];
                
                // Remove double counted area
                if (i > 0 && j > 0)
                    prefix[i][j] -= prefix[i - 1][j - 1];
                
                // Check if sum from (0,0) to (i,j) is <= k
                if (prefix[i][j] <= k)
                    count++;
            }
        }
        
        return count;
    }
};
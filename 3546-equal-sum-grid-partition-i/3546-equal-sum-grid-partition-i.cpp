class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        // Get dimensions of the grid
        int m = grid.size(), n = grid[0].size();
        
        // Step 1: Calculate total sum of all elements
        long long total = 0;
        for (auto &row : grid)
            for (int x : row)
                total += x;
        
        // Step 2: If total sum is odd, equal partition is impossible
        if (total % 2) return false;
        
        // Target sum for each partition
        long long target = total / 2;
        
        // -------------------------------
        // Check row-wise partition
        // -------------------------------
        
        long long sum = 0;
        
        // Try splitting after each row (horizontal cut)
        for (int i = 0; i < m - 1; i++) {
            // Add all elements of current row
            for (int j = 0; j < n; j++)
                sum += grid[i][j];
            
            // If sum equals target, valid partition found
            if (sum == target) return true;
        }
        
        // -------------------------------
        // Check column-wise partition
        // -------------------------------
        
        sum = 0;
        
        // Try splitting after each column (vertical cut)
        for (int j = 0; j < n - 1; j++) {
            // Add all elements of current column
            for (int i = 0; i < m; i++)
                sum += grid[i][j];
            
            // If sum equals target, valid partition found
            if (sum == target) return true;
        }
        
        // No valid partition found
        return false;
    }
};
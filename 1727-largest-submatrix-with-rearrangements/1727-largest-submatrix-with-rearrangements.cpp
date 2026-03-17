class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // 🔹 STEP 1: Convert matrix into "heights" (histogram concept)
        // For each cell, count consecutive 1s vertically (including itself)
        // If current cell is 1 → add height from above row
        // If 0 → it stays 0 (breaks the streak)
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                // If current cell is 1, extend the vertical height
                if (matrix[i][j] == 1) {
                    
                    // Add the height from the cell just above
                    // This gives total consecutive 1s in this column till row i
                    matrix[i][j] += matrix[i - 1][j];
                }
                // If it's 0, we do nothing (height remains 0)
            }
        }
        
        int maxArea = 0;
        
        // 🔹 STEP 2: For each row, try to form largest rectangle
        for (int i = 0; i < n; i++) {
            
            // Copy current row → represents heights of histogram
            vector<int> heights = matrix[i];
            
            // 🔸 IMPORTANT TRICK:
            // We can rearrange columns → so we sort heights in descending order
            // This helps us try best possible widths with tallest heights first
            sort(heights.begin(), heights.end(), greater<int>());
            
            // 🔹 STEP 3: Calculate max area for this row
            for (int j = 0; j < m; j++) {
                
                int height = heights[j];     // height of current column
                int width = j + 1;           // width = number of columns used
                
                // Area = height × width
                maxArea = max(maxArea, height * width);
            }
        }
        
        return maxArea;
    }
};
class Solution {
public:
    // Helper function to perform DFS
    void dfs(vector<vector<int>>& image, vector<vector<bool>>& visited, int sr, int sc, int color, int originalColor) {
        int m = image.size();
        int n = image[0].size();

        // Boundary check: if the pixel is outside the image
        if (sr < 0 || sc < 0 || sr >= m || sc >= n)
            return;

        // If already visited or color is different from original, skip
        if (visited[sr][sc] || image[sr][sc] != originalColor)
            return;

        // Mark current pixel as visited
        visited[sr][sc] = true;

        // Change the color
        image[sr][sc] = color;

        // Recursive calls for 4-directionally adjacent pixels
        dfs(image, visited, sr + 1, sc, color, originalColor); // Down
        dfs(image, visited, sr - 1, sc, color, originalColor); // Up
        dfs(image, visited, sr, sc + 1, color, originalColor); // Right
        dfs(image, visited, sr, sc - 1, color, originalColor); // Left
    }

    // Main function
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];

        // If the original color is the same as the new color, no need to proceed
        if (originalColor == color)
            return image;

        // Create a visited matrix to track processed pixels
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));

        // Start DFS from the source pixel
        dfs(image, visited, sr, sc, color, originalColor);

        return image;
    }
};

class Solution {
public:

    // Function to calculate the average value
    // of a cell and its surrounding neighbors
    int calculateAvg(vector<vector<int>>& img, int i, int j, int row, int col)
    {
        int sum = 0;      // Stores total sum of valid neighbors
        int count = 0;    // Stores count of valid neighbors

        // Traverse 3x3 surrounding grid
        for(int r = i - 1; r <= i + 1; r++)
        {
            for(int c = j - 1; c <= j + 1; c++)
            {
                // Check boundary conditions
                if(r >= 0 && r < row && c >= 0 && c < col)
                {
                    sum += img[r][c]; // Add neighbor value
                    count++;          // Increase valid cell count
                }
            }
        }

        // Return floor average
        return sum / count;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        // Number of rows
        int n = img.size();

        // Number of columns
        int m = img[0].size();

        // Result matrix initialized with size n x m
        vector<vector<int>> result(n, vector<int>(m));

        // Traverse each cell of image
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // Calculate smoothed value for current cell
                int val = calculateAvg(img, i, j, n, m);

                // Store result
                result[i][j] = val;
            }
        }

        // Return final smoothed image
        return result;
    }
};
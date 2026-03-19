int Sum[2][1001];     // Stores prefix sum of (X - Y)
int seenX[2][1001];   // Stores prefix count of X

class Solution {
public:
    static int numberOfSubmatrices(vector<vector<char>>& grid) {

        const int r = grid.size();      // number of rows
        const int c = grid[0].size();   // number of columns

        // Initialize prefix arrays to 0
        memset(Sum[0], 0, (c+1)*sizeof(int));
        memset(Sum[1], 0, (c+1)*sizeof(int));
        memset(seenX[0], 0, (c+1)*sizeof(int));
        memset(seenX[1], 0, (c+1)*sizeof(int));

        int cnt = 0;   // final count of valid submatrices

        // Traverse each row
        for (int i = 0; i < r; i++) {

            bool iEven = (i & 1) == 0;  // current row index (0 or 1 for rolling array)
            bool prv = !iEven;          // previous row

            for (int j = 0; j < c; j++) {

                const char ch = grid[i][j];

                // Check if current cell is X or Y
                bool isX = (ch == 'X');
                bool isY = (ch == 'Y');

                // Build 2D prefix sum for (X - Y)
                // Formula:
                // current = value + left + up - diagonal overlap
                Sum[iEven][j+1] =
                    (isX - isY)                      // +1 for X, -1 for Y
                    + Sum[iEven][j]                 // left
                    + Sum[prv][j+1]                 // up
                    - Sum[prv][j];                  // remove overlap

                // Build prefix sum for counting X
                seenX[iEven][j+1] =
                    isX                             // 1 if X
                    + seenX[iEven][j]              // left
                    + seenX[prv][j+1]              // up
                    - seenX[prv][j];               // remove overlap

                // Now check condition for submatrix (0,0) → (i,j)
                if (Sum[iEven][j+1] == 0 && seenX[iEven][j+1] > 0) {
                    cnt++;   // valid submatrix
                }
            }
        }

        return cnt;
    }
};
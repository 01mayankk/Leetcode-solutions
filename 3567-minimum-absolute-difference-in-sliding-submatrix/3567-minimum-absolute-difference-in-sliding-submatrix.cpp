class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();        // number of rows
        int n = grid[0].size();     // number of columns

        // Result matrix size will be (m-k+1) x (n-k+1)
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        // Traverse every possible k x k submatrix
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                vector<int> v;  // to store elements of current k x k submatrix

                // Step 1: Collect all elements of the submatrix
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        v.push_back(grid[x][y]);
                    }
                }

                // Step 2: Sort the elements
                sort(v.begin(), v.end());

                // Step 3: Remove duplicates
                v.erase(unique(v.begin(), v.end()), v.end());

                // Step 4: Handle edge case (0 or 1 unique element)
                if (v.size() <= 1) {
                    ans[i][j] = 0;  // no difference possible
                } 
                else {
                    // Step 5: Find minimum absolute difference
                    int mn = INT_MAX;

                    for (int p = 0; p < (int)v.size() - 1; p++) {
                        // Since sorted, adjacent difference is minimum candidate
                        mn = min(mn, v[p + 1] - v[p]);
                    }

                    ans[i][j] = mn;
                }
            }
        }

        return ans;  // return final matrix
    }
};
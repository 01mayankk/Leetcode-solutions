// This solution was implemented with assistance from ChatGPT
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;

        int n = grid.size();        // number of rows
        int m = grid[0].size();     // number of columns

        // Result matrix (will temporarily store suffix, then final answer)
        vector<vector<int>> p(n, vector<int>(m));

        // -------------------------------
        // Step 1: Traverse from bottom-right → top-left
        // Store suffix product (product of all elements AFTER current cell)
        // -------------------------------
        long long suffix = 1;   // holds running product of elements after current

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                // At this moment, suffix = product of all elements after (i,j)
                p[i][j] = suffix;

                // Update suffix to include current element for next iteration
                suffix = (suffix * (grid[i][j] % MOD)) % MOD;
            }
        }

        // -------------------------------
        // Step 2: Traverse from top-left → bottom-right
        // Multiply with prefix product (product of all elements BEFORE current cell)
        // -------------------------------
        long long prefix = 1;   // holds running product of elements before current

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Multiply suffix (already stored) with prefix
                // → gives product of all elements except current
                p[i][j] = (p[i][j] * prefix) % MOD;

                // Update prefix to include current element
                prefix = (prefix * (grid[i][j] % MOD)) % MOD;
            }
        }

        return p;
    }
};
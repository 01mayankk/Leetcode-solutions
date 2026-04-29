class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // If only one column → no adjacent column → no score
        if (m == 1) return 0;

        // -----------------------------------------
        // Step 1: Column-wise Prefix Sum
        // col[j][i] = sum of column j from row 0 → i-1
        // Helps in O(1) range sum queries
        // -----------------------------------------
        vector<vector<long long>> col(m, vector<long long>(n + 1, 0));

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                col[j][i + 1] = col[j][i] + grid[i][j];
            }
        }

        // -----------------------------------------
        // Step 2: DP Definition
        // dp[curr][prev] =
        // max score till previous column,
        // where current column height = curr,
        // previous column height = prev
        // -----------------------------------------
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

        // prefix max and suffix max arrays
        // used to optimize transitions
        vector<vector<long long>> prefMax(n + 1, vector<long long>(n + 1, 0));
        vector<vector<long long>> suffMax(n + 1, vector<long long>(n + 1, 0));

        // -----------------------------------------
        // Step 3: Process columns one by one
        // -----------------------------------------
        for (int c = 1; c < m; c++) {

            vector<vector<long long>> newdp(n + 1, vector<long long>(n + 1, 0));

            // -----------------------------------------
            // Step 4: Try all (curr, prev)
            // curr = height of current column
            // prev = height of previous column
            // -----------------------------------------
            for (int curr = 0; curr <= n; curr++) {
                for (int prev = 0; prev <= n; prev++) {

                    if (curr <= prev) {
                        // -----------------------------------------
                        // Case 1: current column is shorter or equal
                        // Contribution comes from current column
                        // rows [curr → prev-1] are white in current
                        // and adjacent to black in previous
                        // -----------------------------------------
                        long long gain = col[c][prev] - col[c][curr];

                        // take best from suffix (all prev >= something)
                        newdp[curr][prev] = max(
                            newdp[curr][prev],
                            suffMax[prev][0] + gain
                        );
                    }
                    else {
                        // -----------------------------------------
                        // Case 2: current column is taller
                        // Contribution comes from previous column
                        // rows [prev → curr-1] are white in previous
                        // and adjacent to black in current
                        // -----------------------------------------
                        long long gain = col[c-1][curr] - col[c-1][prev];

                        newdp[curr][prev] = max({
                            newdp[curr][prev],

                            // best transition without adding gain
                            suffMax[prev][curr],

                            // best transition including gain
                            prefMax[prev][curr] + gain
                        });
                    }
                }
            }

            // -----------------------------------------
            // Step 5: Build prefix max & suffix max
            // These help reduce O(n³) → O(n²)
            // -----------------------------------------
            for (int curr = 0; curr <= n; curr++) {

                // prefix max initialization
                prefMax[curr][0] = newdp[curr][0];

                for (int prev = 1; prev <= n; prev++) {

                    long long penalty = 0;

                    // if prev > curr, subtract overlapping part
                    if (prev > curr)
                        penalty = col[c][prev] - col[c][curr];

                    prefMax[curr][prev] = max(
                        prefMax[curr][prev - 1],
                        newdp[curr][prev] - penalty
                    );
                }

                // suffix max initialization
                suffMax[curr][n] = newdp[curr][n];

                for (int prev = n - 1; prev >= 0; prev--) {
                    suffMax[curr][prev] = max(
                        suffMax[curr][prev + 1],
                        newdp[curr][prev]
                    );
                }
            }

            // move to next column
            dp = move(newdp);
        }

        // -----------------------------------------
        // Step 6: Final Answer
        // max over boundary cases
        // -----------------------------------------
        long long ans = 0;

        for (int k = 0; k <= n; k++) {
            ans = max({ans, dp[0][k], dp[n][k]});
        }

        return ans;
    }
};
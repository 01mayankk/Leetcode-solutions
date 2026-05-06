class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        int m = box.size();        // Number of rows
        int n = box[0].size();     // Number of columns

        // ---------------------------------------------------
        // STEP 1: Apply gravity to each row
        // Stones '#' fall towards the right side
        // ---------------------------------------------------

        for(int i = 0; i < m; i++) {

            // 'empty' stores the position where next stone can fall
            int empty = n - 1;

            // Traverse row from right to left
            for(int j = n - 1; j >= 0; j--) {

                // If obstacle found
                if(box[i][j] == '*') {

                    // Stones cannot cross obstacle
                    // Reset empty position to left of obstacle
                    empty = j - 1;
                }

                // If stone found
                else if(box[i][j] == '#') {

                    // Move stone to the empty position
                    swap(box[i][j], box[i][empty]);

                    // Next available empty position moves left
                    empty--;
                }
            }
        }

        // ---------------------------------------------------
        // STEP 2: Rotate matrix 90 degree clockwise
        // Result matrix size becomes n x m
        // ---------------------------------------------------

        vector<vector<char>> ans(n, vector<char>(m));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                // Rotation formula:
                // new_row = j
                // new_col = m - 1 - i
                ans[j][m - 1 - i] = box[i][j];
            }
        }

        // Return rotated box
        return ans;
    }
};
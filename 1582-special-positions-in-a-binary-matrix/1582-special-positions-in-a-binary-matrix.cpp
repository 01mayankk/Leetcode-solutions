class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int m = mat.size();        // number of rows
        int n = mat[0].size();     // number of columns
        
        vector<int> row(m, 0);     // stores count of 1s in each row
        vector<int> col(n, 0);     // stores count of 1s in each column
        
        // Step 1: Count number of 1s in every row and column
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    row[i]++;      // increment row count
                    col[j]++;      // increment column count
                }
            }
        }
        
        int special = 0;           // stores number of special positions
        
        // Step 2: Check each cell
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                // if cell contains 1 and row + column both have exactly one 1
                if(mat[i][j] == 1 && row[i] == 1 && col[j] == 1){
                    special++;     // found a special position
                }
            }
        }
        
        return special;            // return result
    }
};
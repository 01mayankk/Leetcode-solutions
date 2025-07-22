class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();         
        int n = matrix[0].size();      

        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        vector<int> result;

        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0}; 

        int x = 0, y = 0, dir = 0; 

        for (int i = 0; i < m * n; ++i) {
            result.push_back(matrix[x][y]);
            visited[x][y] = true;

            int nx = x + dx[dir];
            int ny = y + dy[dir];

            
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) {
                dir = (dir + 1) % 4;
                nx = x + dx[dir];
                ny = y + dy[dir];
            }

            x = nx;
            y = ny;
        }

        return result;
    }
};
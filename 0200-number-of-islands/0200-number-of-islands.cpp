class Solution {
public:
    void bfs(vector<vector<char>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = '0'; // mark as visited

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int newX = x + dx;
                int newY = y + dy;

                if (newX >= 0 && newX < grid.size() &&
                    newY >= 0 && newY < grid[0].size() &&
                    grid[newX][newY] == '1') {
                    q.push({newX, newY});
                    grid[newX][newY] = '0'; // mark as visited
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};
 
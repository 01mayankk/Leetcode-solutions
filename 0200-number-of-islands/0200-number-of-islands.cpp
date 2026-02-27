class Solution {
public:

    // BFS function to mark all connected land cells ('1') as visited
    void bfs(vector<vector<char>>& grid, int row, int col) {
        
        // Queue for BFS traversal (stores cell coordinates)
        queue<pair<int, int>> q;
        q.push({row, col});
        
        // Mark starting cell as visited by converting '1' -> '0'
        grid[row][col] = '0';

        // 4 possible directions: Down, Up, Right, Left
        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        // Process all connected land cells
        while (!q.empty()) {
            
            // Get current cell
            auto [x, y] = q.front();
            q.pop();

            // Explore all 4 directions
            for (auto [dx, dy] : directions) {
                int newX = x + dx;
                int newY = y + dy;

                // Check:
                // 1. Within grid bounds
                // 2. Cell contains land ('1')
                if (newX >= 0 && newX < grid.size() &&
                    newY >= 0 && newY < grid[0].size() &&
                    grid[newX][newY] == '1') {

                    // Add to queue for further BFS traversal
                    q.push({newX, newY});

                    // Mark as visited immediately (important to avoid re-processing)
                    grid[newX][newY] = '0';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        
        // Edge case: empty grid
        if (grid.empty()) return 0;

        int row = grid.size();
        int col = grid[0].size();
        int count = 0;  // to count number of islands

        // Traverse entire grid
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                
                // If land cell found → new island discovered
                if (grid[i][j] == '1') {
                    
                    // Use BFS to mark the entire island as visited
                    bfs(grid, i, j);
                    
                    // Increase island count
                    count++;
                }
            }
        }

        return count;
    }
};
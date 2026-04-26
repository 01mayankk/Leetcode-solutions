class Solution {
public:
    int n, m; // dimensions of the grid

    // Possible 4 directions: up, down, left, right
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    // DFS function to detect cycle
    bool dfs(int x, int y, int parentX, int parentY,
             vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {

        // Mark current cell as visited
        visited[x][y] = true;

        // Explore all 4 directions
        for (auto dir : directions) {
            int nx = x + dir[0]; // next row
            int ny = y + dir[1]; // next column

            // Step 1: Check if new cell is inside grid bounds
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            // Step 2: Only move to cells having same character
            if (grid[nx][ny] != grid[x][y])
                continue;

            // Step 3: If the neighbor is not visited → continue DFS
            if (!visited[nx][ny]) {
                if (dfs(nx, ny, x, y, grid, visited))
                    return true; // cycle found in deeper recursion
            }
            else {
                // Step 4: If already visited AND not the parent → cycle exists
                // (parent check avoids false cycle detection)
                if (nx != parentX || ny != parentY)
                    return true;
            }
        }

        // No cycle found from this path
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();       // number of rows
        m = grid[0].size();    // number of columns

        // Create a visited matrix initialized with false
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Traverse every cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // If cell is not visited, start DFS
                if (!visited[i][j]) {
                    
                    // Start DFS with no parent (-1, -1)
                    if (dfs(i, j, -1, -1, grid, visited))
                        return true; // cycle detected
                }
            }
        }

        // If no cycle found in entire grid
        return false;
    }
};
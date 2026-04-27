class Solution {
public:
    // Directions: Up, Right, Down, Left
    vector<vector<int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    
    // Allowed directions for each street type (1-indexed)
    vector<vector<int>> allowed = {
        {},             // dummy (0 index unused)
        {1, 3},         // type 1: left <-> right
        {0, 2},         // type 2: up <-> down
        {3, 2},         // type 3: left <-> down
        {1, 2},         // type 4: right <-> down
        {0, 3},         // type 5: up <-> left
        {0, 1}          // type 6: up <-> right
    };
    
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Visited matrix
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        // BFS queue
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = true;
        
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            // If reached destination
            if(x == n-1 && y == m-1)
                return true;
            
            int type = grid[x][y];
            
            // Check all allowed directions from current cell
            for(int d : allowed[type]) {
                int nx = x + dirs[d][0];
                int ny = y + dirs[d][1];
                
                // Check boundaries
                if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                
                if(vis[nx][ny])
                    continue;
                
                int nextType = grid[nx][ny];
                
                // Opposite direction (important check)
                int opposite = (d + 2) % 4;
                
                // Check if next cell allows connection back
                bool ok = false;
                for(int nd : allowed[nextType]) {
                    if(nd == opposite) {
                        ok = true;
                        break;
                    }
                }
                
                // If valid connection, push to queue
                if(ok) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        
        return false; // no valid path found
    }
};
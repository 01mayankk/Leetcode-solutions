class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {

        // Number of rows and columns
        int m = heightMap.size();
        int n = heightMap[0].size();

        // If grid is too small, no water can be trapped
        if (m <= 2 || n <= 2) return 0;

        // To track already processed cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        /*
            Min-heap (priority queue) to always process
            the cell with the minimum height first
            pair -> {height, {row, col}}
        */
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;

        // Push all boundary cells (left & right columns)
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n-1], {i, n-1}});
            visited[i][0] = visited[i][n-1] = true;
        }

        // Push all boundary cells (top & bottom rows)
        for (int j = 0; j < n; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m-1][j], {m-1, j}});
            visited[0][j] = visited[m-1][j] = true;
        }

        int water = 0;   // Total trapped water

        // Direction vectors for 4 directions (down, up, right, left)
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        // Process cells using BFS guided by min-heap
        while (!pq.empty()) {

            // Get the cell with minimum height
            auto [h, cell] = pq.top();
            pq.pop();

            int x = cell.first;
            int y = cell.second;

            // Explore all 4 neighboring cells
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                // Skip if out of bounds or already visited
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny])
                    continue;

                visited[nx][ny] = true;

                /*
                    If neighbor height is less than current boundary height,
                    water can be trapped
                */
                if (heightMap[nx][ny] < h) {
                    water += h - heightMap[nx][ny];
                }

                /*
                    Push neighbor into heap with updated height.
                    The height becomes the max of:
                    - current boundary height
                    - neighbor height
                */
                pq.push({max(h, heightMap[nx][ny]), {nx, ny}});
            }
        }

        // Return total water trapped
        return water;
    }
};

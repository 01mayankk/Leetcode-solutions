class Solution {
public:
    void bfs(vector<bool>& visited, const vector<vector<int>>& isConnected, int start) {
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int count = 0;
        int size = isConnected.size();
        vector<bool>visited(size+1, false);

        for(int i = 0; i < size; i++)
        {
            if(visited[i] != true)
            {
                visited[i] = true;
                count++;
                bfs(visited, isConnected, i);
            }
        }

        return count;
    }
};
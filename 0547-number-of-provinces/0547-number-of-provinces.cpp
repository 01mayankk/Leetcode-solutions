class Solution {
public:
    
    // DFS function to explore all cities connected to the current city
    void dfs(int city, vector<vector<int>>& isConnected, vector<int>& visited) {
        
        // Mark the current city as visited
        visited[city] = 1;
        
        // Traverse all possible neighboring cities
        for(int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
            
            // If there is a direct connection AND the neighbor is not visited
            if(isConnected[city][neighbor] == 1 && !visited[neighbor]) {
                
                // Recursively visit the neighbor
                dfs(neighbor, isConnected, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();          // Number of cities
        vector<int> visited(n, 0);           // Visited array to track explored cities
        int provinces = 0;                   // Counter for provinces
        
        // Iterate through each city
        for(int i = 0; i < n; i++) {
            
            // If the city is not visited, it means we found a new province
            if(!visited[i]) {
                
                // Perform DFS to mark all cities in this province
                dfs(i, isConnected, visited);
                
                // Increase province count
                provinces++;
            }
        }
        
        return provinces;    // Return total number of provinces
    }
};
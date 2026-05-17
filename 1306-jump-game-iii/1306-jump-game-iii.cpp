class Solution {
public:

    bool canReach(vector<int>& arr, int start) {
        
        // Size of the array
        int n = arr.size();

        // Visited array to keep track of visited indices
        // This prevents infinite loops
        vector<bool> visited(n, false);

        // Queue for BFS traversal
        queue<int> q;

        // Push the starting index into queue
        q.push(start);

        // Mark starting index as visited
        visited[start] = true;

        // Continue BFS until queue becomes empty
        while (!q.empty()) {
            
            // Get front index from queue
            int current = q.front();

            // Remove it from queue
            q.pop();

            // If current index contains 0,
            // we successfully reached the destination
            if (arr[current] == 0) {
                return true;
            }

            // Calculate next forward jump index
            int forward = current + arr[current];

            // Check:
            // 1. Forward index should be inside array
            // 2. It should not be visited already
            if (forward < n && !visited[forward]) {

                // Push forward index into queue
                q.push(forward);

                // Mark as visited
                visited[forward] = true;
            }

            // Calculate next backward jump index
            int backward = current - arr[current];

            // Check:
            // 1. Backward index should be valid
            // 2. It should not be visited already
            if (backward >= 0 && !visited[backward]) {

                // Push backward index into queue
                q.push(backward);

                // Mark as visited
                visited[backward] = true;
            }
        }

        // If BFS completes and no 0 is found
        return false;
    }
};
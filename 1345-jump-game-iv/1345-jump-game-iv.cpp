class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();

        // If array has only one element,
        // we are already at the last index
        if (n == 1)
            return 0;

        // Map each value to all indices having that value
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        // Queue for BFS
        queue<int> q;

        // Visited array to avoid revisiting indices
        vector<bool> visited(n, false);

        // Start BFS from index 0
        q.push(0);
        visited[0] = true;

        int steps = 0;

        // Standard BFS traversal
        while (!q.empty()) {

            int size = q.size();

            // Process one BFS level at a time
            while (size--) {

                int curr = q.front();
                q.pop();

                // If we reached last index,
                // return number of jumps
                if (curr == n - 1)
                    return steps;

                // Store all possible next indices
                vector<int> nextIndices;

                // Jump to curr - 1
                if (curr - 1 >= 0)
                    nextIndices.push_back(curr - 1);

                // Jump to curr + 1
                if (curr + 1 < n)
                    nextIndices.push_back(curr + 1);

                // Jump to all indices having same value
                for (int idx : mp[arr[curr]]) {
                    nextIndices.push_back(idx);
                }

                // Visit all valid next indices
                for (int idx : nextIndices) {

                    if (!visited[idx]) {
                        visited[idx] = true;
                        q.push(idx);
                    }
                }

                // Important Optimization:
                // Clear the list after processing
                // so we don't process same-value indices again
                mp[arr[curr]].clear();
            }

            // One more jump completed
            steps++;
        }

        return -1;
    }
};
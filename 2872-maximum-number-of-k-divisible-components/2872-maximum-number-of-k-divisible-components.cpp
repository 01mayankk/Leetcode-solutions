#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        // -------------------------------
        // Step 1: Build adjacency list of tree
        // -------------------------------
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0; // will store number of valid k-divisible components

        // ---------------------------------------------------------
        // DFS function returns the "sum of subtree % k" for a node
        // ---------------------------------------------------------
        function<long long(int,int)> dfs = [&](int node, int parent) -> long long {
            
            long long sum = values[node];   // start with the node's own value
            
            // Visit all connected children
            for (int nei : adj[node]) {
                if (nei == parent) continue;   // do not go back to parent
                sum += dfs(nei, node);         // add subtree sum of child
            }

            sum %= k;  // we only care about modulo k, not full sum

            // -----------------------------------------------------
            // If subtree sum % k == 0, we can cut edge above it
            // → This subtree becomes an independent component
            // -----------------------------------------------------
            if (sum == 0) {
                count++;   // component successfully formed
                return 0;  // return 0 means nothing left to pass upward
            }

            return sum; // pass remainder to parent to combine
        };

        // Start DFS from root node = 0 (tree, so any root works)
        dfs(0, -1);

        // Final count of k-divisible components
        return count;
    }
};

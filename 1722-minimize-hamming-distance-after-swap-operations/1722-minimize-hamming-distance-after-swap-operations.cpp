class Solution {
public:
    // DSU (Disjoint Set Union) parent array
    vector<int> parent;

    // 🔹 Find the root of a node with path compression
    int find(int x) {
        // If x is not its own parent, recursively find root
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    // 🔹 Union two nodes (merge their components)
    void unite(int x, int y) {
        int px = find(x); // root of x
        int py = find(y); // root of y

        // If roots are different, connect them
        if (px != py)
            parent[px] = py;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        // 🔹 Step 1: Initialize DSU (each node is its own parent initially)
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        // 🔹 Step 2: Build connected components using allowed swaps
        // If two indices can be swapped, they belong to same component
        for (auto &swap : allowedSwaps) {
            unite(swap[0], swap[1]);
        }

        // 🔹 Step 3: Group indices by their root parent (connected components)
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            int root = find(i);          // find representative of component
            groups[root].push_back(i);   // group indices with same root
        }

        int hammingDistance = 0;

        // 🔹 Step 4: Process each group independently
        for (auto &entry : groups) {
            vector<int> indices = entry.second;

            // 🔹 Count frequency of elements in source for this component
            unordered_map<int, int> freq;
            for (int idx : indices) {
                freq[source[idx]]++; // count occurrences
            }

            // 🔹 Try to match elements with target
            for (int idx : indices) {
                // If target value exists in freq → match it
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;  // consume one occurrence
                } 
                else {
                    // No matching value → contributes to Hamming distance
                    hammingDistance++;
                }
            }
        }

        // 🔹 Final minimized Hamming distance
        return hammingDistance;
    }
};
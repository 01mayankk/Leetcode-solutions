/*
Disjoint Set Union (Union-Find)
Used to efficiently check connectivity and avoid cycles
while building the spanning tree.
*/
class DSU {
public:
    vector<int> parent, rankv;  // parent array and rank for union by rank
    int components;             // number of connected components

    // Constructor
    DSU(int n) {
        parent.resize(n);
        rankv.assign(n, 0);

        // Initially every node is its own parent
        iota(parent.begin(), parent.end(), 0);

        components = n;
    }

    // Find function with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union two sets
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        // If both nodes already in same component -> cycle
        if (a == b) return false;

        // Union by rank
        if (rankv[a] < rankv[b])
            swap(a, b);

        parent[b] = a;

        if (rankv[a] == rankv[b])
            rankv[a]++;

        components--;  // reduce number of components
        return true;
    }
};

class Solution {
public:

    /*
    Check if it is possible to build a spanning tree where
    minimum stability >= x using at most k upgrades.
    */
    bool canAchieve(int n, vector<vector<int>>& edges, int k, int x) {
        DSU dsu(n);

        /*
        STEP 1: Process mandatory edges.
        These edges must always be included in the tree.
        */
        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];

            if (must == 1) {
                // If mandatory edge stability is less than x,
                // we cannot satisfy minimum stability condition
                if (s < x) return false;

                // If union fails -> mandatory edges form a cycle
                if (!dsu.unite(u, v)) return false;
            }
        }

        /*
        STEP 2: Use optional edges that already satisfy stability >= x.
        These edges require no upgrade.
        */
        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];

            if (must == 0 && s >= x) {
                dsu.unite(u, v);
            }
        }

        /*
        STEP 3: Use optional edges that can be upgraded.
        If 2*s >= x then upgrading once can reach >= x stability.
        */
        int usedUpgrades = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];

            if (must == 0 && s < x && 2 * s >= x) {
                // Only count upgrade if edge actually connects components
                if (dsu.unite(u, v)) {
                    usedUpgrades++;

                    // If upgrades exceed allowed limit
                    if (usedUpgrades > k)
                        return false;
                }
            }
        }

        // Check if the graph became fully connected
        return dsu.components == 1;
    }

    /*
    Main function to maximize minimum stability.
    Uses Binary Search on answer.
    */
    int maxStability(int n, vector<vector<int>>& edges, int k) {

        /*
        Early check:
        Mandatory edges alone must not form a cycle,
        otherwise spanning tree is impossible.
        */
        {
            DSU dsu(n);
            for (auto &e : edges) {
                if (e[3] == 1) {
                    if (!dsu.unite(e[0], e[1]))
                        return -1;
                }
            }
        }

        // Binary search range for stability
        int low = 1, high = 200000, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if this minimum stability is achievable
            if (canAchieve(n, edges, k, mid)) {
                ans = mid;
                low = mid + 1;   // try to increase stability
            } 
            else {
                high = mid - 1;  // reduce stability
            }
        }

        return ans;
    }
};
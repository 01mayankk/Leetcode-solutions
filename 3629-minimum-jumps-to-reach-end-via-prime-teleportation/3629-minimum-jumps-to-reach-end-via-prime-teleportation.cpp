class Solution {
public:

    // ------------------------------------------------------------
    // Function to find minimum jumps to reach last index
    // ------------------------------------------------------------
    int minJumps(vector<int>& nums) {
        
        int n = nums.size();

        // Edge case:
        // Already at destination
        if (n == 1) {
            return 0;
        }

        // ------------------------------------------------------------
        // STEP 1: Build SPF (Smallest Prime Factor) Sieve
        // SPF helps us:
        // 1. Check whether a number is prime
        // 2. Factorize numbers quickly
        // ------------------------------------------------------------
        
        int MAXV = *max_element(nums.begin(), nums.end());

        vector<int> spf(MAXV + 1);

        for (int i = 0; i <= MAXV; i++) {
            spf[i] = i;
        }

        for (int i = 2; i * i <= MAXV; i++) {
            if (spf[i] == i) { // i is prime
                for (int j = i * i; j <= MAXV; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }

        // ------------------------------------------------------------
        // STEP 2: Build mapping
        //
        // prime factor -> all indices whose values are divisible by it
        //
        // Example:
        // nums = [2,4,6]
        //
        // 2 -> [0,1,2]
        // 3 -> [2]
        // ------------------------------------------------------------
        
        unordered_map<int, vector<int>> factorIndices;

        for (int i = 0; i < n; i++) {

            int x = nums[i];

            // Store unique prime factors
            unordered_set<int> factors;

            while (x > 1) {
                int p = spf[x];
                factors.insert(p);

                while (x % p == 0) {
                    x /= p;
                }
            }

            // Add index to all its prime factors
            for (int p : factors) {
                factorIndices[p].push_back(i);
            }
        }

        // ------------------------------------------------------------
        // STEP 3: BFS
        //
        // Each index is a node.
        // We can:
        // 1. Move left/right
        // 2. Teleport if nums[i] is prime
        // ------------------------------------------------------------
        
        vector<int> dist(n, -1);

        queue<int> q;

        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {

            int i = q.front();
            q.pop();

            int steps = dist[i];

            // --------------------------------------------------------
            // Reached destination
            // --------------------------------------------------------
            if (i == n - 1) {
                return steps;
            }

            // --------------------------------------------------------
            // Move to i - 1
            // --------------------------------------------------------
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = steps + 1;
                q.push(i - 1);
            }

            // --------------------------------------------------------
            // Move to i + 1
            // --------------------------------------------------------
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = steps + 1;
                q.push(i + 1);
            }

            // --------------------------------------------------------
            // Prime Teleportation
            //
            // Allowed only if nums[i] itself is prime
            // --------------------------------------------------------
            int val = nums[i];

            bool isPrime = (val > 1 && spf[val] == val);

            if (isPrime) {

                int p = val;

                // Teleport to every index having number divisible by p
                for (int nxt : factorIndices[p]) {

                    if (dist[nxt] == -1) {
                        dist[nxt] = steps + 1;
                        q.push(nxt);
                    }
                }

                // ----------------------------------------------------
                // IMPORTANT OPTIMIZATION
                //
                // Once processed, clear the vector.
                // Otherwise repeated processing causes TLE.
                // ----------------------------------------------------
                factorIndices[p].clear();
            }
        }

        return -1;
    }
};
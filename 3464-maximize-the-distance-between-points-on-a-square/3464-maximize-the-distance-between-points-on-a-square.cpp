class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {

        // Step 1: Convert 2D boundary points → 1D positions on perimeter
        vector<long long> res;

        for (auto& p : points) {
            int x = p[0], y = p[1];

            // Mapping boundary to a circular perimeter (0 → 4*side)
            if (x == 0) 
                res.push_back(y);                          // left edge (bottom → top)
            else if (y == side) 
                res.push_back((long long)side + x);        // top edge (left → right)
            else if (x == side) 
                res.push_back((long long)side * 3 - y);    // right edge (top → bottom)
            else 
                res.push_back((long long)side * 4 - x);    // bottom edge (right → left)
        }

        // Step 2: Sort positions (linearizing circular boundary)
        sort(res.begin(), res.end());

        // Step 3: Check function → can we pick k points with min distance >= n ?
        auto check = [&](int n) {

            int m = res.size();
            vector<int> idx(k);   // stores indices of chosen points

            // ---- First attempt: start from index 0 ----
            long long curr = res[0];
            idx[0] = 0;

            for (int i = 1; i < k; i++) {

                // Find next point ≥ curr + n
                auto it = lower_bound(res.begin(), res.end(), curr + n);

                if (it == res.end()) 
                    return false;  // cannot pick enough points

                idx[i] = distance(res.begin(), it);
                curr = *it;
            }

            // Check circular condition:
            // last → first gap should also be ≥ n
            if (res[idx[k - 1]] - res[0] <= (long long)side * 4 - n) 
                return true;

            // ---- Try shifting starting point ----
            for (idx[0] = 1; idx[0] < idx[1]; idx[0]++) {

                // Try building sequence from new start
                for (int j = 1; j < k; j++) {

                    // Move forward until gap condition satisfied
                    while (idx[j] < m && res[idx[j]] < res[idx[j - 1]] + n) {
                        idx[j]++;
                    }

                    if (idx[j] == m) 
                        return false;
                }

                // Check circular constraint again
                if (res[idx[k - 1]] - res[idx[0]] <= (long long)side * 4 - n) 
                    return true;
            }

            return false;
        };

        // Step 4: Binary search on answer
        int left = 1;
        int right = (1LL * side * 4) / k + 1;  // tighter upper bound

        while (left + 1 < right) {
            int mid = left + (right - left) / 2;

            if (check(mid)) 
                left = mid;   // try bigger distance
            else 
                right = mid;  // reduce
        }

        return left;
    }
};
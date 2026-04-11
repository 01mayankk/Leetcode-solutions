class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Map each value to list of indices
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // Step 2: Process each value group
        for (auto &it : mp) {
            vector<int> &indices = it.second;

            // If less than 3 occurrences → cannot form a good tuple
            if (indices.size() < 3) continue;

            // Step 3: Try consecutive triplets
            for (int i = 0; i + 2 < indices.size(); i++) {
                int left = indices[i];
                int right = indices[i + 2];

                // Distance = 2 * (k - i)
                int dist = 2 * (right - left);

                ans = min(ans, dist);
            }
        }

        // Step 4: If no valid tuple found
        return (ans == INT_MAX) ? -1 : ans;
    }
};
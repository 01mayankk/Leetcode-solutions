class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Store all indices for each value
        // Key = value in array
        // Value = list of indices where this value appears
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        // Initialize answer with a large value
        int ans = INT_MAX;
        
        // Step 2: Process each unique value independently
        for (auto &it : mp) {
            vector<int> &indices = it.second;
            
            // If less than 3 occurrences → cannot form a valid triplet
            if (indices.size() < 3) continue;
            
            /*
            IMPORTANT OBSERVATION:
            For any i < j < k:
            distance = |i-j| + |j-k| + |k-i|
                     = (j-i) + (k-j) + (k-i)
                     = 2 * (k - i)
            
            So we only need to minimize (k - i)
            */
            
            // Step 3: Try consecutive triples
            // Why consecutive?
            // Because indices are sorted, and closest triple minimizes (k - i)
            for (int i = 0; i + 2 < indices.size(); i++) {
                
                // First index of triple
                int left = indices[i];
                
                // Third index of triple (skip middle one)
                int right = indices[i + 2];
                
                // Distance formula simplified
                int dist = 2 * (right - left);
                
                // Update minimum answer
                ans = min(ans, dist);
            }
        }
        
        // Step 4: If no valid triple found, return -1
        return (ans == INT_MAX) ? -1 : ans;
    }
};
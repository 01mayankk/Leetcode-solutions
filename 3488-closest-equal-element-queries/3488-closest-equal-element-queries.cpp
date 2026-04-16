class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        // Step 1: Create a map to store all indices for each value
        // Example: nums = [1,3,1,4,1] → mp[1] = {0,2,4}
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> answer;
        
        // Step 2: Process each query independently
        for (int q : queries) {
            
            // Value at the queried index
            int val = nums[q];
            
            // All indices where this value appears
            vector<int>& indices = mp[val];
            
            // If the value appears only once → no other index exists
            if (indices.size() == 1) {
                answer.push_back(-1);
                continue;
            }
            
            // Step 3: Find position of current index 'q' in the indices list
            // Using binary search (since indices are sorted)
            int pos = lower_bound(indices.begin(), indices.end(), q) - indices.begin();
            
            int minDist = INT_MAX;
            
            // Step 4: Get the previous occurrence (circular)
            // If pos = 0 → wrap around to last index
            int leftIdx = (pos - 1 + indices.size()) % indices.size();
            int left = indices[leftIdx];
            
            // Step 5: Get the next occurrence (circular)
            // If pos = last → wrap to first index
            int rightIdx = (pos + 1) % indices.size();
            int right = indices[rightIdx];
            
            // Step 6: Compute circular distance
            
            // Distance to left occurrence
            int distLeft = abs(q - left);
            // Take minimum of direct distance and circular wrap distance
            distLeft = min(distLeft, n - distLeft);
            
            // Distance to right occurrence
            int distRight = abs(q - right);
            distRight = min(distRight, n - distRight);
            
            // Step 7: Take the minimum of both directions
            minDist = min(distLeft, distRight);
            
            // Store result
            answer.push_back(minDist);
        }
        
        // Final result for all queries
        return answer;
    }
};
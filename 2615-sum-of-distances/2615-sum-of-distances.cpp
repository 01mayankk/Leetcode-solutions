class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        
        // Result array where ans[i] will store the sum of distances
        // between index i and all other indices with same value
        vector<long long> ans(n, 0);
        
        // Step 1: Group all indices having the same value
        // Example: nums = [1,3,1,1] → mp[1] = {0,2,3}
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        // Step 2: Process each group independently
        for (auto &it : mp) {
            vector<int> &indices = it.second;  // indices of same value
            int m = indices.size();
            
            // Step 3: Build prefix sum array of indices
            // prefix[i] = sum of indices[0] to indices[i]
            vector<long long> prefix(m, 0);
            prefix[0] = indices[0];
            
            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i - 1] + indices[i];
            }
            
            // Step 4: Calculate contribution for each index
            for (int i = 0; i < m; i++) {
                int idx = indices[i];  // actual index in original array
                
                // ---------- LEFT SIDE ----------
                // Distance from current index to all previous indices
                // Formula:
                // (idx - indices[0]) + (idx - indices[1]) + ... 
                // = idx * count - sum_of_left_indices
                if (i > 0) {
                    long long leftSum = prefix[i - 1]; // sum of indices before i
                    long long leftCount = i;          // number of elements before i
                    
                    ans[idx] += (long long)idx * leftCount - leftSum;
                }
                
                // ---------- RIGHT SIDE ----------
                // Distance from current index to all next indices
                // Formula:
                // (indices[i+1] - idx) + (indices[i+2] - idx) + ...
                // = sum_of_right_indices - idx * count
                if (i < m - 1) {
                    long long rightSum = prefix[m - 1] - prefix[i]; // sum after i
                    long long rightCount = m - i - 1;               // count after i
                    
                    ans[idx] += rightSum - (long long)idx * rightCount;
                }
            }
        }
        
        // Final result
        return ans;
    }
};
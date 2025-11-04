class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        // Iterate over all windows of size k
        for (int i = 0; i + k <= n; i++) {
            unordered_map<int, int> freq; // count frequency in current window
            
            // Count frequency of each element in window
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }

            // Store (freq, value) pairs for sorting
            vector<pair<int, int>> items;
            for (auto& [val, f] : freq) {
                items.push_back({f, val});
            }

            // Sort: higher frequency first, break ties by larger value first
            sort(items.begin(), items.end(), [&](auto &a, auto &b) {
                if (a.first == b.first)
                    return a.second > b.second;  // larger value higher priority
                return a.first > b.first;        // higher frequency first
            });

            // Take top x elements (or all if fewer)
            int taken = 0;
            unordered_set<int> keep;
            for (auto &p : items) {
                if (taken == x) break;
                keep.insert(p.second);
                taken++;
            }

            // Compute x-sum: sum only elements that are in "keep"
            int sum = 0;
            for (int j = i; j < i + k; j++) {
                if (keep.count(nums[j])) sum += nums[j];
            }

            ans.push_back(sum);
        }

        return ans;
    }
};

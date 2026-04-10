class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;  // Stores final answers (max of each window)
        
        // Max heap (priority queue)
        // Each element is a pair: {value, index}
        // We store index to check if element is still inside window
        priority_queue<pair<int, int>> pq;
        
        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {
            
            // Step 1: Insert current element into heap
            pq.push({nums[i], i});
            
            // Step 2: Remove elements that are outside the current window
            // Window range is [i-k+1, i]
            // So valid indices must be > i-k
            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop();  // Remove outdated (out of window) elements
            }
            
            // Step 3: Start recording results only when first window is formed
            // First valid window ends at index (k-1)
            if (i >= k - 1) {
                // Top of heap always gives maximum element in current window
                result.push_back(pq.top().first);
            }
        }
        
        return result;  // Return all window maximums
    }
};
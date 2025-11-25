class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_set<int> window;   // Sliding window to store last k elements

        for (int i = 0; i < nums.size(); i++)
        {
            // If current number is already inside the window,
            // it means there exists an index j such that:
            // nums[i] == nums[j] and |i - j| <= k
            if (window.count(nums[i]))
            {
                return true;        // Duplicate within k distance found
            }

            // Add current element to the sliding window
            window.insert(nums[i]);

            // Maintain window size so it never exceeds k elements.
            // Once size > k, we remove the element at index (i - k)
            // This effectively slides the window forward.
            if (window.size() > k)
            {
                window.erase(nums[i - k]);
            }
        }

        // If we finished the loop without finding valid duplicates
        return false;
    }
};

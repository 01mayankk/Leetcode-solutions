class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        // Initialize minimum distance with a very large value
        int minValue = INT_MAX;

        // Traverse the entire array
        for (int i = 0; i < nums.size(); i++) {

            // Check if current element matches the target
            if (nums[i] == target) {

                // Calculate distance from the start index
                int distance = abs(i - start);

                // Update minimum distance if smaller value found
                minValue = min(minValue, distance);
            }
        }

        // Return the minimum distance found
        return minValue;
    }
};
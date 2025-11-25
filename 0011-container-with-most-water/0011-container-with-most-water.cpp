class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0;                       // left pointer at start
        int right = height.size() - 1;      // right pointer at end
        int maxWater = 0;                   // store the maximum area
        
        // Two-pointer approach
        while (left < right) {

            // Width between the two lines
            int width = right - left;

            // Height of the container is limited by the shorter line
            int h = min(height[left], height[right]);

            // Calculate area
            int currArea = h * width;

            // Update maximum area
            maxWater = max(maxWater, currArea);

            // Move the pointer at the shorter line
            if (height[left] < height[right]) {
                left++;     // try to find a taller line on the left
            } else {
                right--;    // try to find a taller line on the right
            }
        }

        return maxWater;
    }
};

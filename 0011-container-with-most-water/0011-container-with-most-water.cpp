class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // Tracks the maximum water area found so far
        int maxWater = INT_MIN;

        // Two pointers: start at both ends
        int left = 0;
        int right = height.size() - 1;

        // Move pointers inward
        while (left < right)
        {
            // Width of the container = distance between pointers
            int width = right - left;

            // Height of the container = shorter of the two lines
            int shortLine = min(height[left], height[right]);

            // Current container area
            int currArea = shortLine * width;

            // Update maximum area
            maxWater = max(currArea, maxWater);

            // Move the pointer at the shorter height
            // Reason: only the shorter side limits the area.
            // Moving the taller side cannot increase height or area.
            if (height[left] < height[right])
            {
                left++;   // try to find a taller line on the left
            }
            else
            {
                right--;  // try to find a taller line on the right
            }
        }

        // Return the maximum area found
        return maxWater;
    }
};

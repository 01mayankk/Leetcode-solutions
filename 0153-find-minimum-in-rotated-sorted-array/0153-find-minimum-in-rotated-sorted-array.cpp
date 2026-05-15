class Solution {
public:
    int findMin(vector<int>& nums) {
        
        // Assume first element is the minimum initially
        int min = nums[0];

        // Binary search boundaries
        int left = 0;
        int right = nums.size() - 1;

        // Variable to store middle index
        int mid;

        // Perform binary search
        while(left <= right)
        {
            // Find middle index safely
            mid = left + (right - left) / 2;

            // If current middle element is smaller than current minimum
            if(nums[mid] < min)
            {
                // Update minimum value
                min = nums[mid];

                // Minimum may still exist on left side
                right = mid - 1;
            }
            else
            {
                // Move to right half
                left = mid + 1;
            }
        }

        // Return the minimum element found
        return min;
    }
};
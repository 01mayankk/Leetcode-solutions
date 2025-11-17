class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        // 'last' will store the index of the previous '1'
        // Initially, no '1' has been seen, so set to -1
        int last = -1;

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // Whenever we find a '1'
            if (nums[i] == 1) {

                // If this is not the first '1' we encountered
                if (last != -1) {

                    // Calculate the gap between current '1' and previous '1'
                    // Gap = (current index - previous index - 1)
                    // If gap is smaller than k → return false
                    if (i - last - 1 < k) {
                        return false;
                    }
                }

                // Update the index of the last seen '1'
                last = i;
            }
        }

        // All gaps between '1's are valid
        return true;
    }
};

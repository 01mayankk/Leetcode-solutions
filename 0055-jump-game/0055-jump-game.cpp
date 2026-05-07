class Solution {
public:
    bool canJump(vector<int>& nums) {

        // Stores the farthest index we can reach
        int farthest = 0;

        // Traverse the array
        for(int i = 0; i < nums.size(); i++) {

            // If current index is greater than farthest reachable index,
            // then we cannot move further
            if(i > farthest) {
                return false;
            }

            // Update the farthest reachable index
            farthest = max(farthest, i + nums[i]);

            // If we can already reach or cross last index
            // no need to continue
            if(farthest >= nums.size() - 1) {
                return true;
            }
        }

        // If traversal completes successfully
        return true;
    }
};
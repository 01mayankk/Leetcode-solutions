class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int left = 0;                     // start pointer
        int right = nums.size() - 1;      // end pointer

        // Two-pointer approach:
        // Move even numbers to the left and odd numbers to the right.
        while(left < right)
        {
            // Case 1: left is even, right is odd -> already correct
            if(nums[left] % 2 == 0 && nums[right] % 2 != 0)
            {
                left++;
                right--;
            }
            // Case 2: left is odd, right is even -> swap to correct positions
            else if(nums[left] % 2 != 0 && nums[right] % 2 == 0)
            {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
            // Case 3: left and right are both odd -> move right pointer
            else if(nums[left] % 2 != 0 && nums[right] % 2 != 0)
            {
                right--;
            }
            // Case 4: left and right are both even -> move left pointer
            else
            {
                left++;
            }
        }

        return nums;
    }
};

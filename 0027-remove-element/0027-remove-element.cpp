class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        int index = 0; // position to place next valid element

        for(int i = 0; i < n; i++) {
            
            // if element is not equal to val
            if(nums[i] != val) {
                nums[index] = nums[i]; // place it in front
                index++;               // move forward
            }
        }

        // index = new length of array
        return index;
    }
};
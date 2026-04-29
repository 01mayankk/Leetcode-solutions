class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();

        // If array has 2 or fewer elements,
        // all are valid since at most 2 duplicates are allowed
        if(n <= 2)
        {
            return n;
        }

        // 'index' represents the position where the next valid element
        // should be placed. First two elements are always valid.
        int index = 2;

        // Start checking from the 3rd element
        for(int i = 2; i < n; i++)
        {
            // Compare current element with the element at (index - 2)
            // This ensures we do NOT allow more than 2 duplicates
            // If they are different → safe to include
            if(nums[i] != nums[index - 2])
            {
                nums[index] = nums[i]; // Place valid element
                index++;               // Move pointer forward
            }
        }

        // 'index' is the length of the modified array
        return index;
    }
};
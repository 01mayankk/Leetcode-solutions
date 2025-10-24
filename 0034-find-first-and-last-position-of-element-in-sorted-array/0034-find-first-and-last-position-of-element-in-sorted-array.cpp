class Solution {
public:

    int findFirst(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        int found = - 1;

        while(start <= end )
        {
            int mid = start + (end - start )/ 2;

            if(nums[mid] == target)
            {
                found = mid;
                end = mid - 1;
            }
            else if(nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return found;
    }
    
    int findLast(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        int found = -1;

        while(start <= end )
        {
            int mid = start + (end - start )/ 2;

            if(nums[mid] == target)
            {
                found = mid;
                start = mid + 1;
            }
            else if(nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return found;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
       return {findFirst( nums,  target) , findLast(nums,  target) };

       
    }
};
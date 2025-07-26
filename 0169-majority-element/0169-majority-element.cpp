class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int count = 0;
        int maxCount = 0;
        int maxValue;

        for(int i = 0; i <= nums.size(); i++)
        {
            if(i == nums.size() - 1)
            {
                break;
            }
            if(nums[i] == nums[i+1])
            {
                count++;
                
            }
            else
            {
                maxCount = max(count, maxCount);
                maxValue = nums[i+1];
                count = 0;
            }
        }

        return maxValue;

    }
};
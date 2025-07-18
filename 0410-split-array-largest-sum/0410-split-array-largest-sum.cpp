class Solution {
public:

    bool isValid(vector<int>&nums, int maxSum, int k)
    {
        int count = 1;
        int currSum = 0;
        for(int val : nums)
        {
            if(currSum + val > maxSum)
            {
                count++;
                currSum = val;
                if(count > k) return false;
            }
            else
            {
                currSum += val;
            }
        }

        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0) ;

        int ans = high;

        while(low <= high)
        {
            int mid = low +(high - low) / 2;

            if(isValid(nums, mid, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};
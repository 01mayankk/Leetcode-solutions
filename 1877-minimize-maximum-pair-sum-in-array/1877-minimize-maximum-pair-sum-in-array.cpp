class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;
        vector<int>result;

        while(left < right)
        {
            int sum = nums[left] + nums[right];
            result.push_back(sum);
            left++;
            right--;
        }

        return *max_element(result.begin(), result.end());
    }
};
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        vector<int>result;
        vector<int>ans;

        for(int i = 0; i < nums.size(); i++ )
        {
            ans.push_back(nums[i]);
            result.push_back(accumulate(ans.begin(), ans.end(), 0));
        }

        return result;
    }
};
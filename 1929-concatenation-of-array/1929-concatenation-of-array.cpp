class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            ans.push_back(nums[i]);
            if(i == n - 1)
            {
                for(int i = 0; i < n; i++)
                {
                    ans.push_back(nums[i]);

                }
            }
        }

        return ans;
    }
};
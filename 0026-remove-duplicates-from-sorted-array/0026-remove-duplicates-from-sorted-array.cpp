class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        set<int>sorted(nums.begin(), nums.end());

        vector<int>v(sorted.begin(), sorted.end());
        nums = v;
        return nums.size();

        
    }
};
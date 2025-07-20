class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> unique;
        vector<int> result;

        for (int i : nums) {
            if (!unique.count(i)) {
                unique.insert(i);
                result.push_back(i);
            }
        }

        nums = result; 

        return nums.size(); 
    }
};

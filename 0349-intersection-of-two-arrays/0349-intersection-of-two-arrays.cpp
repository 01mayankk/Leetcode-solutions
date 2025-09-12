class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        unordered_set<int> s1(nums2.begin(), nums2.end());

        vector<int> v;
        for (int x : s) {
            if (s1.count(x)) {
                v.push_back(x);
            }
        }
        return v;
    }
};

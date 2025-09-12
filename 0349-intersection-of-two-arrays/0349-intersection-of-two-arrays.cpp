class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(), nums1.end());
        set<int> s1(nums2.begin(), nums2.end());

        vector<int> v;

        for (int x : s) {
            if (s1.count(x)) {   // check if x is in s1
                v.push_back(x);
            }
        }

        return v;
    }
};

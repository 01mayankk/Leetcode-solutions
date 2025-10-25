class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> ms1(nums1.begin(), nums1.end());
        multiset<int> ms2(nums2.begin(), nums2.end());
        vector<int> result;

        // iterate over smaller multiset for efficiency
        if (ms1.size() > ms2.size()) swap(ms1, ms2);

        for (int num : ms1) {
            auto it = ms2.find(num);
            if (it != ms2.end()) {
                result.push_back(num);
                ms2.erase(it); // erase one occurrence
            }
        }

        return result;
    }
};
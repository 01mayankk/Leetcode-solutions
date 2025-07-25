class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int maxLen = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int len = 0;
                int x = i, y = j;

                while(x < n && y < m && nums1[x] == nums2[y]) {
                    len++;
                    x++;
                    y++;
                }

                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};

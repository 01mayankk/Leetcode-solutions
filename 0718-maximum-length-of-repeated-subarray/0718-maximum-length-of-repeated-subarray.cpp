// class Solution {
// public:
//     int findLength(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size(), m = nums2.size();
//         int maxLen = 0;

//         for(int i = 0; i < n; ++i) {
//             for(int j = 0; j < m; ++j) {
//                 int len = 0;
//                 int x = i, y = j;

//                 while(x < n && y < m && nums1[x] == nums2[y]) {
//                     len++;
//                     x++;
//                     y++;
//                 }

//                 maxLen = max(maxLen, len);
//             }
//         }

//         return maxLen;
//     }
// };

//Above is a brute force where we are matching each element of nums1 to nums2 one by one which give TLE as it will take O((m *n)* min(m, n))

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        if(n == 0 || m == 0)
        {
            return 0;
        }
        int maxLen = 0;

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m ;j++)
            {
                if(nums1[i-1] == nums2[j-1])
                {
                    dp[i][j] = 1 + dp[i - 1][j-1];
                }

            maxLen = max(maxLen, dp[i][j]);

            }

        }

        return maxLen;
        

        
    }
};

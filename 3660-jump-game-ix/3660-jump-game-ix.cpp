class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        
        int n = nums.size();

        /*
            pre[i]  -> maximum value from 0 to i
            suf[i]  -> minimum value from i to n-1
            res[i]  -> answer for index i
        */
        vector<int> pre(n), suf(n), res(n);

        // Build prefix maximum array
        pre[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], nums[i]);
        }

        // Build suffix minimum array
        suf[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suf[i] = min(suf[i + 1], nums[i]);
        }

        /*
            Last index always belongs to a component
            whose maximum value is pre[n-1]
        */
        res[n - 1] = pre[n - 1];

        /*
            Traverse from right to left

            Observation:

            If:
                pre[i] > suf[i + 1]

            then an inversion exists across boundary.

            Meaning:
                some left element > some right element

            So both parts are connected and belong
            to same component.

            Therefore:
                res[i] = res[i + 1]



            Otherwise:

                pre[i] < suf[i + 1]

            No inversion exists across boundary.

            So a new component starts here.

            Maximum reachable value for this new
            component is simply pre[i].
        */
        for (int i = n - 2; i >= 0; i--) {

            // Same connected component
            if (pre[i] > suf[i + 1]) {
                res[i] = res[i + 1];
            }

            // New connected component starts
            else {
                res[i] = pre[i];
            }
        }

        return res;
    }
};
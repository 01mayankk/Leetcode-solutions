class Solution {
public:
    vector<int> findGoodIntegers(int n) {

        // Map to store sum of cubes and how many ways it can be formed
        unordered_map<long long, int> mp;

        // Maximum limit for cube root (since i^3 <= n)
        int l = cbrt(n);

        // Iterate over all possible values of i
        for(int i = 1; i <= l; i++)
        {
            // Compute i^3 once to avoid recomputation
            long long v1 = 1LL * pow(i , 3);

            // Iterate over j starting from i (to avoid duplicate pairs like (i,j) and (j,i))
            for(int j = i; j <= l; j++)
            {
                // Compute sum of cubes: i^3 + j^3
                long long sum = v1 + 1LL * pow(j , 3);

                // If sum exceeds n, no need to check further j (since j is increasing)
                if(sum > n)
                {
                    break;
                }

                // Count how many times this sum appears
                mp[sum]++;
            }
        }

        // Vector to store all valid "good integers"
        vector<int> result;

        // Traverse the map
        for(auto& elem : mp)
        {
            // If a number can be represented in at least 2 different ways
            // as sum of cubes → it's a "good integer"
            if(elem.second >= 2)
            {
                result.push_back(elem.first);
            }
        }

        // Sort the result in ascending order
        sort(result.begin(), result.end());

        return result;
    }
};
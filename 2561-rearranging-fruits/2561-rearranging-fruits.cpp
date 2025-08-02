class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> count;
        int globalMin = INT_MAX;

        // Step 1: Count items and track global min
        for (int x : basket1) 
        {
            count[x]++;
            globalMin = min(globalMin, x);
        }
        
        for (int x : basket2) 
        {
            count[x]--;
            globalMin = min(globalMin, x);
        }

        long long total = 0;

        // Step 2: Check if balancing is possible
        for (auto& [k, v] : count) 
        {
            if (v % 2 != 0)
            {
                return -1;  // odd difference
            } 
            total += abs(v);
        }

        // Step 3: Build swap list
        vector<int> im;
        for (auto& [num, v] : count) 
        {
            for (int i = 0; i < abs(v) / 2; ++i) 
            {
                im.push_back(num);
            }
        }

        // Step 4: Sort swap list
        sort(im.begin(), im.end());

        // Step 5: Choose cheapest swaps
        long long ans = 0;
        long long doubleMin = 2LL * globalMin;
        int half = im.size() / 2;
        for (int i = 0; i < half; ++i) 
        {
            ans += min((long long)im[i], doubleMin);
        }

        // Step 6: Return result
        return ans; 
    }
};
class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int>result;

        for(int i = 0; i <= n; i++)
        {
            bitset<64>value(i);
            result.push_back(value.count());
        }

        return result;
    }
};
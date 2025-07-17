class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int>map;
        vector<int>result;
                
        for(int i = 0; i < nums.size() ; i++)
        {
            map[nums[i]]++;
        }

        priority_queue<pair<int, int>>max;

        for(auto it = map.begin(); it != map.end(); it++)
        {
            max.push(make_pair(it->second, it->first));
        }

        for(int i = 0; i < k; i++)
        {
            result.push_back(max.top().second);
            max.pop();
        }

        return result;
    }
};
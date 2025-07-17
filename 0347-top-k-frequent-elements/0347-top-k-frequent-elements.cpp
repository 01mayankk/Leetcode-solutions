// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
        
//         unordered_map<int, int>map;
//         vector<int>result;
                
//         for(int i = 0; i < nums.size() ; i++)
//         {
//             map[nums[i]]++;
//         }

//         priority_queue<pair<int, int>>max;

//         for(auto it = map.begin(); it != map.end(); it++)
//         {
//             max.push(make_pair(it->second, it->first));
//         }

//         for(int i = 0; i < k; i++)
//         {
//             result.push_back(max.top().second);
//             max.pop();
//         }

//         return result;
//     }
// };

//Above we are using max heap to get the max frequent element on top but we can also go for min heap in the time complexity will reduce to O(n log K) will in max it will always be O(n log n).

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> result;

        // Step 1: Count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Use min-heap to store top k frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto& [num, count] : freq) {
            minHeap.push({count, num});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Step 3: Extract k most frequent
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};

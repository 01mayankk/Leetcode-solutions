class Solution {
public:
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        // number -> index
        unordered_map<int, int> mp;

        for (int i = 0; i < numbers.size(); i++) {
            
            int comp = target - numbers[i];

            // If complement already exists
            if (mp.find(comp) != mp.end()) {
                
                // Return 1-based indices
                return {mp[comp] + 1, i + 1};
            }

            // Store current number and its index
            mp[numbers[i]] = i;
        }

        return {};
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int>map;// make map to store value 

        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i]; // make a complement 
            if (map.find(complement) != map.end()) { // check whether complement already seen or not if not mp.end() will return the iterator means the last elemnt is reached of the map
                return {map[complement], i};
            }
            map[nums[i]] = i; //other wise push the element as key and index as value;

            
        }

        return {};
    }
};
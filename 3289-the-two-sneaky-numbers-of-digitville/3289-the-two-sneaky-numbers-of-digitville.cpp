class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        
        // Vector to store numbers that appear exactly twice
        vector<int> result;

        // Unordered map to store frequency of each number
        unordered_map<int, int> freq;

        // Step 1: Count frequency of each element in the array
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;   // Increment count for nums[i]
        }

        // Step 2: Traverse the map to find numbers with frequency = 2
        for (auto& elem : freq) {
            // elem.first  -> the number
            // elem.second -> its frequency
            if (elem.second == 2) {
                result.push_back(elem.first);   // Add number to result
            }
        }

        // Step 3: Sort the result before returning
        sort(result.begin(), result.end());

        // Step 4: Return all numbers that appeared exactly twice
        return result;
    }
};

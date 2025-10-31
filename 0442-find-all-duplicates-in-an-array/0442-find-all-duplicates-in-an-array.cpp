class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        // Hash map to store frequency of each element in the array
        unordered_map<int, int> freq;

        // Vector to store the final result (numbers appearing exactly twice)
        vector<int> result;

        // Step 1: Count frequency of each number
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;   // Increment count for the current number
        }

        // Step 2: Traverse through the frequency map
        for (auto& elem : freq) {
            // elem.first  -> number (key)
            // elem.second -> frequency (value)

            // If a number appears exactly twice, add it to the result
            if (elem.second == 2) {
                result.push_back(elem.first);
            }
        }

        // Step 3: Sort the result in ascending order (for consistent output)
        sort(result.begin(), result.end());

        // Step 4: Return the list of duplicate numbers
        return result;
    }
};

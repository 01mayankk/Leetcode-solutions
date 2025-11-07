// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) { // This will work fine but not optimized as per question it is running in TC : O(n) but also taking auxiliary space O(n) but question demand constant which means I have to do it in Space Complexity : O(1)
        
//         // Hash map to store frequency of each element in the array
//         unordered_map<int, int> freq;

//         // Vector to store the final result (numbers appearing exactly twice)
//         vector<int> result;

//         // Step 1: Count frequency of each number
//         for (int i = 0; i < nums.size(); i++) {
//             freq[nums[i]]++;   // Increment count for the current number
//         }

//         // Step 2: Traverse through the frequency map
//         for (auto& elem : freq) {
//             // elem.first  -> number (key)
//             // elem.second -> frequency (value)

//             // If a number appears exactly twice, add it to the result
//             if (elem.second == 2) {
//                 result.push_back(elem.first);
//             }
//         }

//         // Step 3: Sort the result in ascending order (for consistent output)
//         sort(result.begin(), result.end());

//         // Step 4: Return the list of duplicate numbers
//         return result;
//     }
// };



class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) { // TC : O(n) and SC : O(1) as we are not taking any other space except the vector which is used for storing result

        // Vector to store the final result
        // It will contain all numbers that appear exactly twice
        vector<int> result;

        // -------------------------------
        // Idea:
        // 1. The array contains numbers in the range [1, n],
        //    where n = nums.size().
        // 2. We can use the sign (+/-) of each element in nums itself
        //    to mark whether we have seen a number before.
        // 3. No need for extra data structures like maps or sets.
        // -------------------------------

        for (int i = 0; i < nums.size(); i++) {

            // Get the index corresponding to the current number.
            // We subtract 1 because the array is 0-indexed
            // and numbers are in range [1, n].
            int index = abs(nums[i]) - 1;

            // If the value at nums[index] is already negative,
            // that means we have visited this 'index' before,
            // i.e., the number (index + 1) has appeared once already.
            if (nums[index] < 0) {

                // Since it's already negative, the current number
                // is a duplicate → add it to the result vector.
                result.push_back(abs(nums[i]));
            }
            else {
                // Otherwise, mark this number as "seen" by negating
                // the value at that corresponding index.
                // This tells us that we've encountered (index + 1) once.
                nums[index] = -nums[index];
            }
        }

        // After the loop, all duplicates are collected in 'result'.
        // We don’t need to restore nums to its original form unless required,
        // because the problem does not ask for it.
        return result;
    }
};



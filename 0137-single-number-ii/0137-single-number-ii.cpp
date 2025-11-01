// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         // Hash map to store the frequency of each number in the array
//         // This helps identify which element appears exactly once
//         unordered_map<int, int> freq;

//         // Step 1: Count frequency of each element
//         for (int i = 0; i < nums.size(); i++) {
//             freq[nums[i]]++; // Increment count for nums[i]
//         }

//         // Step 2: Find and return the element that appears only once
//         for (auto elem : freq) {
//             if (elem.second == 1) {
//                 return elem.first; // Return the unique element
//             }
//         }

//         // Step 3: Return 0 if no unique element is found (edge case)
//         return 0;
//     }
// };

/*
\U0001f9e0 Explanation:
This approach uses a hash map (unordered_map) to store the frequency of each number.
Then we simply return the number that appears exactly once.

⏱️ Time Complexity: O(n)
   - We traverse the array once to count frequencies and once to find the unique element.

\U0001f4be Space Complexity: O(n)
   - Extra space is used to store elements in the hash map.

⚠️ Note:
Although this solution works correctly and runs in linear time,
it does NOT meet the "constant extra space" constraint mentioned in the problem.
*/
 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;

        for (int num : nums) {
            // Update 'ones' with bits appearing once
            ones = (ones ^ num) & ~twos;

            // Update 'twos' with bits appearing twice
            twos = (twos ^ num) & ~ones;
        }

        return ones; // The bits appearing once are in 'ones'
    }
};

/*
\U0001f9e9 Explanation:
- 'ones' stores bits that appeared once so far.
- 'twos' stores bits that appeared twice.
- When a bit appears the third time, it's cleared from both.

\U0001f4a1 Bit trick:
    Each bit position cycles through:
        0 → 1 → 2 → 0  (mod 3 pattern)

⏱️ Time Complexity: O(n)
   We traverse the array once.

\U0001f4be Space Complexity: O(1)
   We use only two integer variables (ones, twos).

✅ Meets the problem constraints (O(n), O(1))
*/

// class Solution {
// public:
//     int repeatedNTimes(vector<int>& nums) {

//         // Total length of the array (size = 2N)
//         int len = nums.size();

//         // Hash map to store frequency of each number
//         unordered_map<int, int> freq;

//         // Variable to store the number repeated N times
//         int reqNo;

//         // Count frequency of each element in the array
//         for (auto& i : nums) {
//             freq[i]++;
//         }

//         // Traverse the frequency map
//         for (auto& elem : freq) {
//             // The required element appears exactly N times
//             // Since array size is 2N, N = len / 2
//             if (elem.second == len / 2) {
//                 reqNo = elem.first;
//                 break;  // Stop once found
//             }
//         }

//         // Return the element repeated N times
//         return reqNo;
//     }
// };


class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        // The array size is 2N
        // One number appears exactly N times
        // All other numbers appear only once

        // Key observation:
        // The repeated element must appear at least twice
        // within any window of 4 consecutive elements

        int n = nums.size();

        // Traverse the array
        for (int i = 0; i < n; i++) {

            // Check immediate next element
            if (i + 1 < n && nums[i] == nums[i + 1])
                return nums[i];

            // Check element two positions ahead
            if (i + 2 < n && nums[i] == nums[i + 2])
                return nums[i];

            // Check element three positions ahead
            // Checking up to i+3 is sufficient by problem guarantee
            if (i + 3 < n && nums[i] == nums[i + 3])
                return nums[i];
        }

        // This line will never execute because
        // the repeated element is guaranteed to exist
        return -1;
    }
};

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        // Map to store how many times each prefix sum occurs
        unordered_map<int, int> prefixFreq;

        // One empty prefix with sum = 0
        prefixFreq[0] = 1;

        int prefixSum = 0;  // running sum
        int count = 0;      // answer

        for (int i = 0; i < nums.size(); i++) {

            // Add current element to running sum
            prefixSum += nums[i];

            // If (prefixSum - goal) exists,
            // it means there are subarrays ending here with sum == goal
            if (prefixFreq.find(prefixSum - goal) != prefixFreq.end()) {
                count += prefixFreq[prefixSum - goal];
            }

            // Store/update the frequency of current prefixSum
            prefixFreq[prefixSum]++;
        }

        return count;
    }
};

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

        unordered_map<int,int> freq;

        // Count frequency of each element
        for (int x : nums)
            freq[x]++;

        // Find maximum frequency
        int maxFreq = 0;
        for (auto &p : freq)
            maxFreq = max(maxFreq, p.second);

        // Count total elements having max frequency
        int ans = 0;
        for (auto &p : freq) {
            if (p.second == maxFreq)
                ans += p.second;  // ADD frequency, not value
        }

        return ans;
    }
};

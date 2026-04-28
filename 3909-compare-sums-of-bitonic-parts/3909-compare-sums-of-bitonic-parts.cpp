class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        
        int n = nums.size();

        // Variables to store sum of increasing and decreasing parts
        long long incSum, descSum;

        int peak = -1; // index of peak element in bitonic array

        // Step 1: Find the peak element (greater than both neighbors)
        for(int i = 1; i < n - 1; i++)
        {
            if(nums[i] > nums[i + 1] && nums[i] > nums[i - 1])
            {
                peak = i; // store index of peak
            }
        }

        // Step 2: Calculate sum of increasing part (0 to peak)
        incSum = accumulate(nums.begin(), nums.begin() + peak + 1, 0LL);

        // Step 3: Calculate sum of decreasing part (peak to end)
        // Note: peak is included in both sums
        descSum = accumulate(nums.begin() + peak, nums.end(), 0LL);

        // Step 4: Compare both sums
        if(incSum > descSum)
        {
            return 0; // increasing part has greater sum
        }
        else if(incSum == descSum)
        {
            return -1; // both sums are equal
        }

        return 1; // decreasing part has greater sum
    }
};
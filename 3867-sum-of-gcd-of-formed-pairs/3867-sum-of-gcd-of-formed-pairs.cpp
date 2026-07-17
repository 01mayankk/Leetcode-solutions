class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        
        // Track the running maximum element from the start up to the current index
        int maxi = nums[0];
        prefixGcd[0] = nums[0];
        
        // Step 1: Compute the prefixGcd array where prefixGcd[i] = gcd(nums[i], max(nums[0...i]))
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxi);
        }
        
        // Step 2: Sort the prefixGcd array in non-decreasing order as requested
        sort(prefixGcd.begin(), prefixGcd.end());
        
        long long totalSum = 0;
        int left = 0, right = n - 1;
        
        // Step 3: Use a two-pointer approach to pair the smallest unpaired element 
        // with the largest unpaired element, calculating the GCD of each pair.
        // If n is odd, the middle element is automatically skipped when left == right.
        while (left < right) {
            totalSum += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        
        return totalSum;
    }
};
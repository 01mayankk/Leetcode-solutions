class Solution {
public:
    long long maxPairStrength(std::vector<int>& nums) {
        long long max_strength = 0;
        int n = nums.size();
        
        // Iterate through all possible pairs of distinct indices (i, j)
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Find the greatest common divisor (GCD) for the pair
                long long g = gcd(nums[i], nums[j]);
                
                // Calculate the strength using 64-bit integers to prevent overflow
                long long strength = (1LL * nums[i] * nums[j]) / (g * g);
                
                // Update the maximum strength found so far
                max_strength = max(max_strength, strength);
            }
        }
        
        return max_strength;
    }
};
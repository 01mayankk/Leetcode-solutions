class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        
        long long sum = 0;   // Total sum of all elements in nums
        long long f0 = 0;    // Value of F(0)
        
        // Step 1: Compute total sum and F(0)
        // F(0) = 0*nums[0] + 1*nums[1] + ... + (n-1)*nums[n-1]
        for (int i = 0; i < n; i++) {
            sum += nums[i];               // accumulate total sum
            f0 += (long long)i * nums[i]; // compute F(0)
        }
        
        long long ans = f0;   // Initialize answer with F(0)
        long long prev = f0;  // Stores previous rotation value (F(k-1))
        
        // Step 2: Use recurrence relation to compute F(k)
        // Formula:
        // F(k) = F(k-1) + sum - n * nums[n - k]
        //
        // Why?
        // - Each element shifts right → contributes +sum
        // - Last element moves to front → subtract n * that element
        
        for (int k = 1; k < n; k++) {
            // Compute current rotation value using previous one
            long long curr = prev + sum - (long long)n * nums[n - k];
            
            ans = max(ans, curr); // Update maximum value
            prev = curr;          // Move to next iteration
        }
        
        return ans; // Return maximum F(k)
    }
};
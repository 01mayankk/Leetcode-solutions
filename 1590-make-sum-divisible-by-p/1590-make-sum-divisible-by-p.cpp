class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        // Step 1: Calculate total sum of array
        long long totalSum = 0;
        for(int x : nums) totalSum += x;

        // Step 2: If already divisible by p -> no need to remove anything
        int target = totalSum % p;       // we must remove a subarray with this remainder
        if(target == 0) return 0;

        /*
            Key Idea:
            Find the smallest subarray whose sum % p = target
            Because removing that subarray makes totalSum divisible by p.
        */

        unordered_map<int,int> mp;
        mp[0] = -1;                      // prefix mod = 0 at index -1 (important for edge cases)

        long long prefix = 0;            // stores running prefix sum modulo p
        int minLen = nums.size();        // we try to minimize this

        for(int i = 0; i < nums.size(); i++){
            
            // Build prefix sum with mod p to avoid overflow
            prefix = (prefix + nums[i]) % p;

            // We want a previous prefix such that:
            // (prefix[i] - prefix[j]) % p = target  → subarray(j+1 ... i) is removable
            long long need = (prefix - target + p) % p;

            // If such prefix exists, calculate subarray length
            if(mp.count(need)) 
                minLen = min(minLen, i - mp[need]);

            // Store / update latest index of this prefix modulo
            mp[prefix] = i;
        }

        // If no subarray found → answer is -1
        return minLen == nums.size() ? -1 : minLen;
    }
};

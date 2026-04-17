#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to reverse digits of a number
    // Example: 120 -> 21
    static int reverseNum(int x) {
        int rev = 0;
        
        while (x > 0) {
            int digit = x % 10;     // extract last digit
            rev = rev * 10 + digit; // build reversed number
            x /= 10;               // remove last digit
        }
        
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        
        // Map stores: reversed number -> latest index
        unordered_map<int, int> mp;
        mp.reserve(n); // optimization to avoid rehashing
        
        int minDist = INT_MAX;

        // Traverse array
        for (int i = 0; i < n; i++) {
            
            int current = nums[i];
            
            // 🔹 Check if current number exists as a reversed value of some previous number
            if (mp.find(current) != mp.end()) {
                
                // Found a mirror pair
                int prevIndex = mp[current];
                
                // Update minimum distance
                minDist = min(minDist, i - prevIndex);
            }
            
            // 🔹 Store reverse of current number
            int reversed = reverseNum(current);
            mp[reversed] = i; // store latest index
        }

        // If no mirror pair found, return -1
        return (minDist == INT_MAX) ? -1 : minDist;
    }
};
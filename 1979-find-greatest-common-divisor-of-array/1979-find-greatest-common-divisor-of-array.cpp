class Solution {
public:
    int findGCD(vector<int>& nums) {

        // Find the largest element in the array
        int maxi = *max_element(nums.begin(), nums.end());

        // Find the smallest element in the array
        int mini = *min_element(nums.begin(), nums.end());

        // The required answer is the GCD of
        // the minimum and maximum elements.
        return gcd(maxi, mini);
    }
};
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {

        // Sort the array in ascending order
        // This brings smaller numbers together
        sort(nums.begin(), nums.end());

        int sum = 0;

        // Traverse the array by jumping 2 indices at a time
        // nums[i] is always the minimum of the pair (nums[i], nums[i+1])
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];   // Add the smaller element of each pair
        }

        // Return the maximum possible sum of minimums
        return sum;
    }
};

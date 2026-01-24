class Solution {
public:
    int minPairSum(vector<int>& nums) {

        // Step 1: Sort the array
        // This allows us to pair smallest with largest values
        sort(nums.begin(), nums.end());

        int left = 0;                       // Pointer to the smallest element
        int right = nums.size() - 1;        // Pointer to the largest element

        vector<int> result;                 // Stores sum of each formed pair

        // Step 2: Form pairs: smallest + largest
        // This balancing minimizes the maximum pair sum
        while (left < right) {
            int sum = nums[left] + nums[right];
            result.push_back(sum);          // Store pair sum
            left++;                         // Move to next smallest
            right--;                        // Move to next largest
        }

        // Step 3: Return the maximum pair sum among all pairs
        return *max_element(result.begin(), result.end());
    }
};

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        // Calculate total sum of all elements
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        vector<int> answer(n);
        int leftSum = 0;

        for (int i = 0; i < n; i++) {
            // Right sum = total sum - current element - left sum
            int rightSum = totalSum - nums[i] - leftSum;

            // Store absolute difference
            answer[i] = abs(leftSum - rightSum);

            // Update left sum for next index
            leftSum += nums[i];
        }

        return answer;
    }
};
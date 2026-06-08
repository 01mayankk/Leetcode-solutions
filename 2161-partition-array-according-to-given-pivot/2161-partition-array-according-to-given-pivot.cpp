class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        // Store elements less than pivot
        vector<int> smaller;

        // Store elements equal to pivot
        vector<int> equal;

        // Store elements greater than pivot
        vector<int> greater;

        // Partition elements into three groups
        for (int num : nums) {

            if (num < pivot) {
                smaller.push_back(num);
            }
            else if (num == pivot) {
                equal.push_back(num);
            }
            else {
                greater.push_back(num);
            }
        }

        // Final answer vector
        vector<int> result;

        // Add all elements smaller than pivot
        for (int num : smaller) {
            result.push_back(num);
        }

        // Add all elements equal to pivot
        for (int num : equal) {
            result.push_back(num);
        }

        // Add all elements greater than pivot
        for (int num : greater) {
            result.push_back(num);
        }

        return result;
    }
};
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {

//         // Sort the array in ascending order
//         sort(nums.begin(), nums.end());

//         // The last two elements are the largest
//         int largest = nums[nums.size() - 1];
//         int secondLargest = nums[nums.size() - 2];

//         // Return the required product
//         return (largest - 1) * (secondLargest - 1);
//     }
// };


class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // Store the largest and second largest elements
        int largest = 0;
        int secondLargest = 0;

        // Traverse the array only once
        for (int num : nums) {

            // If current number is the new largest
            if (num >= largest) {
                secondLargest = largest; // Previous largest becomes second largest
                largest = num;           // Update largest
            }

            // Otherwise, check if it can become the second largest
            else if (num > secondLargest) {
                secondLargest = num;
            }
        }

        // Return the required product
        return (largest - 1) * (secondLargest - 1);
    }
};
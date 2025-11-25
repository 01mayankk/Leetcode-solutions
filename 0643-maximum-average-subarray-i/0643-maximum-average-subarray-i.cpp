// class Solution {
// public:
//     double findMaxAverage(vector<int>& nums, int k) {
        
//         int sum = 0;
//         double maxAvg = INT_MIN;  // allow negative averages
//         int window = 0;

//         for (int i = 0; i < nums.size(); i++)
//         {
//             // add current element to window sum
//             sum += nums[i];
//             window++;

//             // once window exceeds k, slide it
//             if (window > k)
//             {
//                 sum -= nums[i - k];   // remove left-most element
//                 window--;             // keep window size valid
//             }

//             // only compute average when window size == k
//             if (window == k)
//             {
//                 double avg = (double)sum / k;   // correct floating division
//                 maxAvg = max(maxAvg, avg);
//             }
//         }

//         return maxAvg;
//     }
// };


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        // Step 1: compute sum of first window of size k
        double windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        double maxAvg = windowSum / k;

        // Step 2: slide the window from index k to end
        for (int i = k; i < nums.size(); i++) {

            // Slide the window: add right element, remove left element
            windowSum += nums[i] - nums[i - k];

            // Update maximum average
            maxAvg = max(maxAvg, windowSum / k);
        }

        return maxAvg;
    }
};

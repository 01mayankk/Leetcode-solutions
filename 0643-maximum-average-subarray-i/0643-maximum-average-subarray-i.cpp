class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int sum = 0;
        double maxAvg = INT_MIN;  // allow negative averages
        int window = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            // add current element to window sum
            sum += nums[i];
            window++;

            // once window exceeds k, slide it
            if (window > k)
            {
                sum -= nums[i - k];   // remove left-most element
                window--;             // keep window size valid
            }

            // only compute average when window size == k
            if (window == k)
            {
                double avg = (double)sum / k;   // correct floating division
                maxAvg = max(maxAvg, avg);
            }
        }

        return maxAvg;
    }
};

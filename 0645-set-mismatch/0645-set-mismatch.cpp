class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int n = nums.size();

        // Frequency array
        // freq[i] stores how many times i appears
        vector<int> freq(n + 1, 0);

        // Count occurrences of each number
        for(int num : nums)
        {
            freq[num]++;
        }

        int duplicate = -1;
        int missing = -1;

        // Check frequency of numbers from 1 to n
        for(int i = 1; i <= n; i++)
        {
            // Appears twice -> duplicate number
            if(freq[i] == 2)
            {
                duplicate = i;
            }

            // Never appeared -> missing number
            if(freq[i] == 0)
            {
                missing = i;
            }
        }

        // Return {duplicate, missing}
        return {duplicate, missing};
    }
};
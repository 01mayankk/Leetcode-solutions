class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        int n = nums.size();

        /*
            We use line sweep / difference array approach.

            For every pair:
            nums[i] and nums[n-1-i]

            We calculate how many moves are needed
            for every possible target sum.
        */

        // Difference array
        vector<int> diff(2 * limit + 2, 0);

        // Process each pair
        for(int i = 0; i < n / 2; i++)
        {
            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = min(a, b);
            int high = max(a, b);

            int pairSum = a + b;

            /*
                For a target sum:

                2 moves needed initially for all sums.

                Then optimize ranges:
            */

            // Range where 1 move is enough starts
            diff[low + 1] -= 1;

            // Exact sum where 0 moves needed
            diff[pairSum] -= 1;

            // After exact sum, back to 1 move
            diff[pairSum + 1] += 1;

            // After this range, back to 2 moves
            diff[high + limit + 1] += 1;
        }

        /*
            Initially assume every pair needs 2 moves
        */
        int moves = n;
        int answer = INT_MAX;

        // Try every possible target sum
        for(int sum = 2; sum <= 2 * limit; sum++)
        {
            // Apply sweep line changes
            moves += diff[sum];

            // Store minimum moves
            answer = min(answer, moves);
        }

        return answer;
    }
};
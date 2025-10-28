class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();  // Store the size of the array

        // -------------------------------
        // Step 1️⃣: Mark visited numbers
        // -------------------------------
        // For every number in the array:
        // - Convert it to an index (value - 1)
        // - Mark that index as "visited" by making nums[index] negative.
        // 
        // The trick: Each number in [1, n] maps to an index [0, n-1].
        // Example: value 3 → index 2
        // Once a number is seen, we mark nums[index] = -abs(nums[index])
        // so we can detect which numbers never appeared later.
        // -------------------------------
        for (int i = 0; i < n; i++) {
            // abs(nums[i]) ensures we handle already-negative values correctly
            int index = abs(nums[i]) - 1;  // Convert value → 0-based index

            // If this index hasn’t been marked yet (still positive), mark it
            if (nums[index] > 0) {
                nums[index] = -nums[index];  // Mark as visited by negating it
            }
        }

        // -------------------------------
        // Step 2️⃣: Collect missing numbers
        // -------------------------------
        // After marking:
        // - Negative value → index has been visited → number exists
        // - Positive value → index never visited → number missing
        //
        // So, for every positive nums[i],
        // the missing number is (i + 1).
        // -------------------------------
        vector<int> missing;  // To store the missing numbers

        for (int i = 0; i < n; i++) {
            // nums[i] > 0 means the number (i+1) was never seen
            if (nums[i] > 0) {
                missing.push_back(i + 1);
            }
        }

        // -------------------------------
        // Step 3️⃣: Return the result
        // -------------------------------
        // The vector 'missing' now contains all numbers from 1 to n
        // that did not appear in the input array.
        // -------------------------------
        return missing;
    }
};

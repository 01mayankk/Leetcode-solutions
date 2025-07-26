class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Boyer-Moore Voting Algorithm for finding elements that appear more than ⌊ n/3 ⌋ times
        // In a list of size n, there can be **at most two elements** that appear more than n/3 times.
        
        // Step 1: Initialize two candidate variables and their respective counts
        int candidate1 = INT_MIN, candidate2 = INT_MIN; // Placeholders for potential majority elements
        int count1 = 0, count2 = 0; // Their corresponding vote counts

        // Step 2: Iterate through the array to find the two most likely majority candidates
        for (int num : nums) {
            // If current number matches candidate1, increment its count
            if (num == candidate1) {
                count1++;
            }
            // If current number matches candidate2, increment its count
            else if (num == candidate2) {
                count2++;
            }
            // If count1 is zero, assign current number as new candidate1
            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }
            // If count2 is zero, assign current number as new candidate2
            else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }
            // If current number doesn't match any candidate and both counts are non-zero,
            // decrement both counts (simulating a "vote out")
            else {
                count1--;
                count2--;
            }
        }

        // Step 3: Verify whether these candidates actually appear more than n/3 times
        count1 = 0;
        count2 = 0;

        // Count actual occurrences of candidate1 and candidate2 in the array
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++; // use else if to avoid counting the same number twice
        }

        // Step 4: Add valid majority elements to the result
        vector<int> result;
        int n = nums.size();

        // Only include the candidate if it appears more than ⌊ n/3 ⌋ times
        if (count1 > n / 3) result.push_back(candidate1);
        if (count2 > n / 3) result.push_back(candidate2);

        // Return the result vector containing up to 2 majority elements
        return result;
    }
};
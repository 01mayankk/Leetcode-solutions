class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        // STEP 1: Sort the array in ascending order
        // Sorting is crucial because the minimum absolute difference
        // will always be found between two adjacent elements in a sorted array
        sort(arr.begin(), arr.end());

        // This will store the final answer (pairs with minimum difference)
        vector<vector<int>> result;

        // Initialize minimum difference with the largest possible value
        int minDiff = INT_MAX;

        // STEP 2: First pass to find the minimum absolute difference
        // We compare each element only with its next neighbor
        for (int i = 0; i < arr.size() - 1; i++) {

            // Since the array is sorted, arr[i+1] >= arr[i],
            // so absolute difference is simply (arr[i+1] - arr[i])
            int diff = arr[i + 1] - arr[i];

            // Update the minimum difference found so far
            minDiff = min(minDiff, diff);
        }

        // STEP 3: Second pass to collect all pairs that have minDiff
        for (int i = 0; i < arr.size() - 1; i++) {

            // If the difference of adjacent elements equals minDiff,
            // this pair is part of the answer
            if (arr[i + 1] - arr[i] == minDiff) {
                result.push_back({arr[i], arr[i + 1]});
            }
        }

        // STEP 4: Return all minimum-difference pairs
        return result;
    }
};

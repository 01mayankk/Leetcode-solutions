class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        // Step 1: Sort the array so we can process elements in increasing order.
        sort(arr.begin(), arr.end());

        // Step 2: The first element must always be 1.
        // If it is greater than 1, we decrement it to 1.
        arr[0] = 1;

        int n = arr.size();

        // Step 3: Traverse the remaining elements.
        for (int i = 1; i < n; i++) {

            // If the current element is more than 1 greater than
            // the previous element, reduce it to previous + 1.
            //
            // This ensures:
            // 1. arr[i] >= arr[i - 1]
            // 2. arr[i] - arr[i - 1] <= 1
            if (arr[i] - arr[i - 1] > 1) {
                arr[i] = arr[i - 1] + 1;
            }

            // If arr[i] <= arr[i - 1] + 1,
            // we leave it unchanged because it already satisfies
            // the required condition.
        }

        // The array is now valid, and since it is non-decreasing,
        // the last element is the maximum possible value.
        return arr[n - 1];
    }
};
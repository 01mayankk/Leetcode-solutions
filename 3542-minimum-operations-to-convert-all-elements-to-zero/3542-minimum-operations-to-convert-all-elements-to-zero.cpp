class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;

        // Stack to track increasing sequence of active numbers
        // Start with 0 as a sentinel (it represents the 'zeroed out' base)
        stack<int> st;
        st.push(0);

        // Traverse each number in the array
        for (int x : nums) {

            // Step 1: Remove all numbers larger than the current one
            // Because once we see a smaller number, all previous larger numbers
            // cannot extend further (their segment ended)
            while (!st.empty() && st.top() > x) {
                st.pop();
            }

            // Step 2: If the current number is greater than the top,
            // it starts a new "block" (new operation)
            if (st.empty() || st.top() < x) {
                operations++;   // we need a new operation for this level
                st.push(x);     // push it into stack as active
            }

            // Step 3: If st.top() == x, we do nothing
            // because we can reuse the same operation that handled this value earlier
        }

        // Step 4: Return total number of operations counted
        return operations;
    }
};

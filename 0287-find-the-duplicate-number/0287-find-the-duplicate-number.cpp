class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
         * Problem: Find the duplicate number in an array of size n+1 
         * containing integers from 1 to n.
         * 
         * Constraint: Must use O(1) extra space and O(n) time.
         * 
         * Idea: Treat the array as a linked list where:
         *    - Each index is a node.
         *    - The value at nums[i] is the next pointer (like next node index).
         * 
         * Because one number repeats, this "linked list" will have a cycle.
         * The duplicate number is the entry point of the cycle.
         * 
         * Approach: Use Floyd's Tortoise and Hare (Cycle Detection Algorithm)
         */

        // Step 1: Initialize two pointers (slow and fast)
        int slow = nums[0];  // moves 1 step at a time
        int fast = nums[0];  // moves 2 steps at a time

        /*
         * Phase 1: Find intersection point inside the cycle
         * The loop will eventually break when both pointers meet inside the cycle.
         */
        do {
            slow = nums[slow];         // move slow by one step
            fast = nums[nums[fast]];   // move fast by two steps
        } while (slow != fast);        // continue until they meet

        /*
         * Phase 2: Find the entrance of the cycle (duplicate number)
         * Move one pointer to the start of the array (nums[0])
         * and keep the other at the intersection point.
         * Then move both one step at a time until they meet again.
         * The meeting point is the duplicate number.
         */
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        // Both pointers meet at the duplicate number
        return slow;
    }
};

/*
----------------------------------------
\U0001f552 Time Complexity: O(n)
----------------------------------------
- Both slow and fast pointers traverse the array at most twice.
- Thus, total steps are proportional to n.

\U0001f4be Space Complexity: O(1)
----------------------------------------
- No extra data structures used.
- Only a few integer variables are maintained.

✅ Why This Works:
----------------------------------------
- The duplicate number causes a "cycle" in the number chain.
- Floyd's algorithm efficiently detects and locates this cycle.
- Hence, we can identify the duplicate without modifying the array.
*/

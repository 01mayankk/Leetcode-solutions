/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    int pairSum(ListNode* head) {

        // ----------------------------
        // STEP 1: Find middle node
        // ----------------------------
        // slow moves 1 step at a time
        // fast moves 2 steps at a time
        // When fast reaches the end,
        // slow will be at the start of the second half.
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // ----------------------------
        // STEP 2: Reverse second half
        // ----------------------------
        // Example:
        // 1 -> 2 -> 3 -> 4
        // slow points to 3
        // Reverse: 3 -> 4 becomes 4 -> 3
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr != nullptr) {

            // Store next node before breaking link
            ListNode* nextNode = curr->next;

            // Reverse current link
            curr->next = prev;

            // Move prev and curr one step forward
            prev = curr;
            curr = nextNode;
        }

        // prev is now the head of the reversed second half
        // Example: 4 -> 3
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;

        // Variable to store maximum twin sum found
        int maxTwinSum = 0;

        // ----------------------------
        // STEP 3: Calculate twin sums
        // ----------------------------
        // Traverse both halves together
        // firstHalf:  1 -> 2
        // secondHalf: 4 -> 3
        //
        // Twin pairs:
        // (1,4), (2,3)
        while (secondHalf != nullptr) {

            // Calculate current twin sum
            int twinSum = firstHalf->val + secondHalf->val;

            // Update answer if larger sum found
            maxTwinSum = max(maxTwinSum, twinSum);

            // Move both pointers forward
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // ----------------------------
        // STEP 4: Return answer
        // ----------------------------
        return maxTwinSum;
    }
};
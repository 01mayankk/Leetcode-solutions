class Solution {
public:
    bool isPalindrome(ListNode* head) {

        /* -----------------------------------------------------
          STEP 1: Find the middle of the linked list
          -----------------------------------------------------

          We use fast & slow pointers:
          - slow moves 1 step
          - fast moves 2 steps

          When fast reaches end, slow will be at the midpoint.

          Example (odd nodes):  1 → 2 → 3 → 2 → 1
                               slow = 3 (middle)

          Example (even nodes): 1 → 2 → 2 → 1
                               slow = second 2 (right middle)
        ------------------------------------------------------*/

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // slow steps one
            fast = fast->next->next;  // fast steps two
        }
        // Now slow = start of second half


        /* -----------------------------------------------------
          STEP 2: Reverse the second half of the list
          -----------------------------------------------------

          Why reverse?
          - To compare left half (forward direction)
          - With right half (reverse direction)

          After reversing, the list will conceptually become:

            Original: 1 → 2 → 3 → 2 → 1
            Reversed second half:     1 ← 2 ← 3

          We store the head of reversed part in 'prev'
        ------------------------------------------------------*/

        ListNode* prev = nullptr;   // this will become new head of reversed half

        while(slow != nullptr) {    // reverse till end
            ListNode* nextNode = slow->next; // save next
            slow->next = prev;               // reverse pointer
            prev = slow;                     // move prev forward
            slow = nextNode;                 // move slow forward
        }
        // Now prev = head of reversed second half


        /* -----------------------------------------------------
          STEP 3: Compare first half and reversed second half
          -----------------------------------------------------

          left  starts from head
          right starts from prev (middle->end reversed)

          Walk both pointers together:
          If all values match → palindrome
          If a mismatch found → NOT palindrome
        ------------------------------------------------------*/

        ListNode* left = head;
        ListNode* right = prev;

        while(right != nullptr) {   // only second half needs to be checked
            if(left->val != right->val)
                return false;       // mismatch → not palindrome

            left = left->next;
            right = right->next;
        }

        // If loop completes without mismatch → palindrome
        return true;
    }
};

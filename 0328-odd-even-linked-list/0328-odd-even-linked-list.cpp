// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head) {

//         // Edge case:
//         // If the list is empty or has only one node,
//         // it is already arranged, so return as is.
//         if (!head || !head->next) 
//             return head;

//         // 'odd' will point to nodes at odd positions (1st, 3rd, 5th, ...)
//         ListNode* odd = head;

//         // 'even' will point to nodes at even positions (2nd, 4th, 6th, ...)
//         ListNode* even = head->next;

//         // Store the head of even list so we can attach it
//         // after the odd list at the end
//         ListNode* evenHead = even;

//         // Traverse until there are no more pairs of odd and even nodes
//         while (even && even->next) {

//             // Connect current odd node to the next odd node
//             // (which is even->next)
//             odd->next = even->next;
//             odd = odd->next;

//             // Connect current even node to the next even node
//             // (which is odd->next after rearrangement)
//             even->next = odd->next;
//             even = even->next;
//         }

//         // After rearranging, attach the even list
//         // after the last odd node
//         odd->next = evenHead;

//         // Head remains the same, now reordered as required
//         return head;
//     }
// };

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // Base case:
        // If the list is empty or has only one node,
        // odd-even rearrangement is not needed
        if (head == nullptr || head->next == nullptr)
            return head;

        // 'odd' will always point to the last node
        // in the odd-positioned list
        ListNode* odd = nullptr;

        // 'even' will always point to the last node
        // in the even-positioned list
        ListNode* even = nullptr;

        // 'evenHead' stores the first even-positioned node
        // so that we can attach the even list after odd list
        ListNode* evenHead = nullptr;

        // Pointer used to traverse the original linked list
        ListNode* curr = head;

        // Index to track position of nodes (1-based indexing)
        int index = 1;

        // Traverse the entire linked list
        while (curr != nullptr) {

            // If the position is odd
            if (index % 2 == 1) {

                // If this is the first odd node,
                // initialize 'odd'
                if (odd == nullptr) {
                    odd = curr;
                }
                // Otherwise, append current node
                // to the odd-positioned list
                else {
                    odd->next = curr;
                    odd = odd->next;
                }
            }
            // If the position is even
            else {

                // If this is the first even node,
                // initialize 'even' and save its head
                if (even == nullptr) {
                    even = curr;
                    evenHead = even;
                }
                // Otherwise, append current node
                // to the even-positioned list
                else {
                    even->next = curr;
                    even = even->next;
                }
            }

            // Move to the next node in original list
            curr = curr->next;

            // Move to next position
            index++;
        }

        // Very important step:
        // Break the link after the last even node
        // to avoid forming a cycle
        if (even != nullptr)
            even->next = nullptr;

        // Attach the even-positioned list
        // at the end of the odd-positioned list
        odd->next = evenHead;

        // Head remains the same (first odd node)
        return head;
    }
};


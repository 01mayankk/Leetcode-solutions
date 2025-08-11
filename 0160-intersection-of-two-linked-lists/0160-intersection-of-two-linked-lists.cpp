/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // If either list is empty, no intersection possible
        if (!headA || !headB) return nullptr;

        // Two pointers starting at heads of both lists
        ListNode* pA = headA;
        ListNode* pB = headB;

        // Traverse until they meet or both become null
        while (pA != pB) {
            // Move pointer forward; if it reaches end, switch to other list's head
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }

        // Either intersection node or nullptr if no intersection
        return pA;
    }
};

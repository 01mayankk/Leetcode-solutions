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

        // If either list is empty, they can never intersect
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        // Two pointers starting at the heads of both lists
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        // Move both pointers until they meet
        while (temp1 != temp2) {

            // If temp1 reaches the end of list A,
            // redirect it to the head of list B
            // otherwise move to next node
            temp1 = (temp1 == nullptr) ? headB : temp1->next;

            // If temp2 reaches the end of list B,
            // redirect it to the head of list A
            // otherwise move to next node
            temp2 = (temp2 == nullptr) ? headA : temp2->next;
        }

        // When loop exits:
        // - Either both point to the intersection node
        // - Or both are nullptr (no intersection)
        return temp1;
    }
};

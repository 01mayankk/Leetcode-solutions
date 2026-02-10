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
    ListNode* swapPairs(ListNode* head) {

        // Dummy node simplifies edge cases (like swapping the head)
        ListNode dummy(0);
        dummy.next = head;

        // 'prev' points to the node before the current pair
        ListNode* prev = &dummy;

        // Traverse while there are at least two nodes to swap
        while (prev->next && prev->next->next) {

            // First node of the pair
            ListNode* first = prev->next;

            // Second node of the pair
            ListNode* second = first->next;

            // Swapping the pair by changing links
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move 'prev' to the end of the swapped pair
            prev = first;
        }

        // New head is dummy.next
        return dummy.next;
    }
};

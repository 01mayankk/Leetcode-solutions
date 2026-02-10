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
    ListNode* deleteDuplicates(ListNode* head) {
        
        // If the list is empty or has only one node,
        // no duplicates can exist
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Pointer to traverse the linked list
        ListNode* temp = head;

        // Traverse until the second last node
        while (temp->next != nullptr) {
            
            // Pointer to store duplicate node
            ListNode* curr;

            // If current value is same as next value,
            // a duplicate is found
            if (temp->val == temp->next->val) {
                
                // Store the duplicate node
                curr = temp->next;

                // Skip the duplicate node
                temp->next = temp->next->next;

                // Free memory of the removed node
                delete(curr);
            }
            else {
                // Move forward only when no duplicate is found
                temp = temp->next;
            }
        }

        // Head of the modified list
        return head;
    }
};

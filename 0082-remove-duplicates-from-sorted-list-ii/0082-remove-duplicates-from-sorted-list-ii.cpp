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
        
        // If list is empty, return immediately
        if (head == nullptr) 
            return head;
        
        // Dummy node to handle edge cases (like duplicates at head)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // prev always points to the last confirmed non-duplicate node
        ListNode* prev = dummy;
        
        // curr is used to traverse the list
        ListNode* curr = head;
        
        // Traverse the linked list
        while (curr != nullptr) {
            
            // Check if current node starts a duplicate sequence
            if (curr->next != nullptr && curr->val == curr->next->val) {
                
                // Store duplicate value
                int duplicateValue = curr->val;
                
                // Skip all nodes having this duplicate value
                while (curr != nullptr && curr->val == duplicateValue) {
                    curr = curr->next;
                }
                
                // Connect prev to the next distinct node
                prev->next = curr;
            }
            else {
                // No duplicate found, move prev forward
                prev = curr;
                
                // Move curr forward
                curr = curr->next;
            }
        }
        
        // Return new head (dummy->next handles head deletion cases)
        return dummy->next;
    }
};

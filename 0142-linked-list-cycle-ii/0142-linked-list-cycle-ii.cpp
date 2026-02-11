/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode *detectCycle(ListNode *head) {
        
        // If list is empty or has only one node,
        // it cannot form a cycle
        if(head == nullptr || head->next == nullptr)
            return nullptr;
        
        // Initialize two pointers for Floyd's Algorithm
        ListNode* slow = head;  // moves 1 step
        ListNode* fast = head;  // moves 2 steps
        
        // Step 1: Detect whether a cycle exists
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;           // move slow by 1
            fast = fast->next->next;     // move fast by 2
            
            // If slow and fast meet, a cycle exists
            if(slow == fast)
            {
                // Step 2: Find starting node of the cycle
                
                // Move one pointer to the head
                ListNode* entry = head;
                
                // Move both pointers one step at a time
                // They will meet at the cycle start
                while(entry != slow)
                {
                    entry = entry->next;
                    slow = slow->next;
                }
                
                // entry (or slow) is the beginning of the cycle
                return entry;
            }
        }
        
        // If no cycle was detected
        return nullptr;
    }
};

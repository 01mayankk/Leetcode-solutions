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
    bool hasCycle(ListNode *head) {
        
        // If list is empty or has only 1 node → it can't form a cycle
        if(head == nullptr || head->next == nullptr)
        {
            return false;
        }

        // Slow pointer moves 1 step at a time
        ListNode* slow = head;

        // Fast pointer moves 2 steps at a time
        ListNode* fast = head;

        // Continue until fast reaches end (meaning no cycle exists)
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;           // slow moves by 1
            fast = fast->next->next;     // fast moves by 2

            // If fast meets slow at some node → cycle detected
            if(slow == fast)
            {
                return true;
            }
        }

        // If loop ends, fast reached null → no cycle exists
        return false;
    }
};

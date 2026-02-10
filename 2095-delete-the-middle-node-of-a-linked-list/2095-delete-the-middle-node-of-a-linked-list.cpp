class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // Case 1: If the list is empty OR has only one node
        // The middle node is the only node, so deleting it means return null
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        // Initialize slow pointer at head
        // slow will eventually stop at the node JUST BEFORE the middle node
        ListNode* slow = head;

        // Initialize fast pointer two steps ahead
        // This setup ensures slow ends one node before the middle
        ListNode* fast = head->next->next;

        // Move slow by 1 step and fast by 2 steps
        // fast reaching the end means slow is before the middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // move slow one step
            fast = fast->next->next;    // move fast two steps
        }

        // Now slow->next points to the middle node
        // To delete the middle node, skip it by changing links
        slow->next = slow->next->next;

        // Return the modified list head
        return head;
    }
};

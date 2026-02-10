class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Step 1: Count the total number of nodes in the linked list
        int length = 0;
        ListNode* temp = head;

        // Traverse the list to calculate its length
        while (temp != nullptr) {
            length++;               // increment node count
            temp = temp->next;      // move to next node
        }

        // Step 2: If the node to be removed is the head itself
        // This happens when n equals the total length of the list
        if (n == length)
            return head->next;      // remove head and return new head

        // Step 3: Move temp to the node just BEFORE the target node
        // We need to stop at (length - n - 1) index
        temp = head;
        for (int i = 0; i < length - n - 1; i++) {
            temp = temp->next;      // move one step forward
        }

        // Step 4: Delete the nth node from the end
        // Skip the target node by adjusting the next pointer
        temp->next = temp->next->next;

        // Step 5: Return the head of the updated list
        return head;
    }
};

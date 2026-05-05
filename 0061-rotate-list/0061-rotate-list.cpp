class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        // Edge cases:
        // - Empty list
        // - Single node (no rotation effect)
        // - k = 0 (no rotation needed)
        if(head == nullptr || head->next == nullptr || k == 0)
            return head;

        // Step 1: Find length of linked list
        // Also get the last node (tail)
        int n = 1;                 // start from 1 because we are at head
        ListNode* temp = head;

        while(temp->next) {
            temp = temp->next;
            n++;
        }
        // Now:
        // n = length of list
        // temp = last node (tail)

        // Step 2: Make the list circular
        // Connect tail to head
        temp->next = head;

        // Step 3: Optimize k
        // Rotating n times gives same list
        // So reduce unnecessary rotations
        k = k % n;

        // Step 4: Find new tail
        // New tail will be at position (n - k - 1)
        // We move (n - k) steps from head to reach new tail
        int steps = n - k;
        ListNode* newTail = head;

        for(int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // Step 5: Set new head
        // Node after newTail becomes new head
        ListNode* newHead = newTail->next;

        // Break the circular link
        newTail->next = nullptr;

        // Return updated head
        return newHead;
    }
};
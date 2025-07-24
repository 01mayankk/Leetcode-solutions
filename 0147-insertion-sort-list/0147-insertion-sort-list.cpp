class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0); 
        dummy->next = head;

        ListNode* lastSorted = head;       
        ListNode* curr = head->next;       

        while (curr) {
            if (lastSorted->val <= curr->val) {
                
                lastSorted = lastSorted->next;
            } else {
                
                ListNode* prev = dummy;
                while (prev->next->val < curr->val) {
                    prev = prev->next;
                }

                
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }

            curr = lastSorted->next;
        }

        return dummy->next;
    }
};

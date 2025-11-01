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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Base cases: if list is empty or no numbers to remove
        if (head == nullptr || nums.empty()) {
            return head;
        }

        // Step 1: Use unordered_set for faster lookup (O(1) 
        unordered_set<int> toDelete(nums.begin(), nums.end());

        // Step 2: Create a dummy node to handle deletion of head node easily
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        // Step 3: Traverse the list
        while (curr != nullptr) {
            // If current node’s value is in the deletion list
            if (toDelete.find(curr->val) != toDelete.end()) {
                // Skip and unlink the node
                prev->next = curr->next;
                curr = prev->next;
            } else {
                // Otherwise move ahead
                prev = curr;
                curr = curr->next;
            }
        }

        // Step 4: Return new head (dummy->next)
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // Max Heap (by default priority_queue in C++ is max heap)
        priority_queue<int> pq;

        // Step 1: Push all elements into max heap
        for(int num : nums) {
            pq.push(num);   // push element directly
        }

        // Step 2: Remove the largest element (k-1) times
        // because the kth largest will be on top after removing k-1 elements
        for(int i = 0; i < k - 1; i++) {
            pq.pop();
        }

        // Step 3: The top element is kth largest
        return pq.top();
    }
};
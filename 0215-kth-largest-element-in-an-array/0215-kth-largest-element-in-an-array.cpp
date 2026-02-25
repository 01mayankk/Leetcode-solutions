class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> max;
        for(int i : nums)
        {
            max.push(i);
        }
        
        for( int i = 0; i < k - 1; i++)
        {
            
            max.pop();
        }

        return max.top();
    }
};
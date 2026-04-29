class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // 'candidate' stores the current majority candidate
        // 'vote' keeps track of its frequency balance
        int candidate = nums[0];
        int vote = 1;
        
        // Traverse the array starting from index 1
        for(int i = 1; i < nums.size(); i++)
        {
            // If vote becomes 0, we choose a new candidate
            if(vote == 0)
            {
                candidate = nums[i];
                vote = 1;
            }
            // If current element matches candidate → increase vote
            else if(nums[i] == candidate)
            {
                vote++;
            }
            // If different → decrease vote (cancel out effect)
            else
            {
                vote--;
            }
        }

        // The remaining candidate is the majority element
        return candidate;
    }
};
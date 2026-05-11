class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        // Vector to store final separated digits
        vector<int> ans;

        // Traverse each number in the array
        for(int i = 0; i < nums.size(); i++)
        {
            // If number has more than 1 digit
            if(nums[i] > 9)
            {
                int copy = nums[i];

                // Stack is used to maintain correct digit order
                stack<int> st;

                // Extract digits from right to left
                while(copy > 0)
                {
                    int digit = copy % 10; // Get last digit

                    st.push(digit); // Store digit in stack

                    copy /= 10; // Remove last digit
                }

                // Pop digits from stack to get original order
                while(!st.empty())
                {
                    ans.push_back(st.top());

                    st.pop();
                }
            }
            else
            {
                // Single digit numbers are added directly
                ans.push_back(nums[i]);
            }
        }

        // Return final separated digit array
        return ans;
    }
};
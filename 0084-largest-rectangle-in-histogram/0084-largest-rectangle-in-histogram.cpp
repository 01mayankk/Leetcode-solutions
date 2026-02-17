class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        stack<int> st;   // stack will store indices
        int maxArea = 0;
        
        // Traverse all bars
        for(int i = 0; i <= n; i++) {
            
            // If stack is not empty AND
            // current height is smaller than stack top height
            // then calculate area
            while(!st.empty() && 
                  (i == n || heights[st.top()] >= heights[i])) {
                
                int height = heights[st.top()];
                st.pop();
                
                // If stack becomes empty,
                // it means this height is smallest so far
                int width;
                if(st.empty()) {
                    width = i;   // entire width
                } else {
                    width = i - st.top() - 1;
                }
                
                maxArea = max(maxArea, height * width);
            }
            
            st.push(i);
        }
        
        return maxArea;
    }
};

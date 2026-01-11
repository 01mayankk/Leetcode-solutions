class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        // Edge case: empty matrix
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Histogram heights array
        vector<int> heights(cols, 0);

        int maxArea = 0;

        // Process each row
        for (int i = 0; i < rows; i++) {

            // Update histogram heights
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    heights[j] += 1;   // Extend height
                else
                    heights[j] = 0;    // Reset on zero
            }

            // Compute largest rectangle in histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {

            // Use 0 height sentinel at end
            int currHeight = (i == n) ? 0 : heights[i];

            // Calculate area while stack violates increasing order
            while (!st.empty() && currHeight < heights[st.top()]) {

                int height = heights[st.top()];
                st.pop();

                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};

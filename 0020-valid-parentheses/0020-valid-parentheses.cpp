class Solution {
public:
    bool isValid(string s) {
        
        // Stack to store opening brackets
        stack<char> st;

        // Traverse each character in the string
        for (char ch : s)
        {
            // If it's an opening bracket, push into stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                // If it's a closing bracket BUT stack is empty → invalid
                if (st.empty()) {
                    return false;
                }

                // Get the top opening bracket
                char top = st.top();
                st.pop();

                // Check if the pair matches
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) 
                {
                    return false;
                }
            }
        }

        // If stack is empty → all brackets matched correctly
        // If not empty → some opening brackets were not closed
        return st.empty();
    }
};

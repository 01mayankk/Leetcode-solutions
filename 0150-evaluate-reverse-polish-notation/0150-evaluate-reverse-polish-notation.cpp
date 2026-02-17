class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        // Stack to store operands (numbers)
        stack<int> st;
        
        // Traverse each token in the input
        for(auto& token : tokens) {
            
            // Check if current token is an operator
            // If yes, we need to pop two operands
            if(token == "+" || token == "-" || 
               token == "*" || token == "/") {
                
                // IMPORTANT:
                // First popped element is second operand (b)
                int b = st.top(); 
                st.pop();
                
                // Second popped element is first operand (a)
                int a = st.top(); 
                st.pop();
                
                int value;  // To store result of operation
                
                // Perform the correct operation
                if(token == "+") 
                    value = a + b;
                else if(token == "-") 
                    value = a - b;
                else if(token == "*") 
                    value = a * b;
                else 
                    value = a / b;  // C++ automatically truncates toward 0
                
                // Push result back into stack
                st.push(value);
            }
            else {
                // If token is not operator,
                // it must be a number → convert string to int
                st.push(stoi(token));
            }
        }
        
        // Final result will remain at the top of stack
        return st.top();
    }
};

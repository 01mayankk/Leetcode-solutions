class Solution {
private:
    // Helper function to build the parentheses combinations
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // Base case: when the string reaches the maximum length (2 * n)
        if (current.length() == n * 2) {
            result.push_back(current);
            return;
        }
        
        // Add an opening parenthesis if we haven't used all 'n' of them
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }
        
        // Add a closing parenthesis if there are more open ones than closed ones
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        // Start the recursion with 0 open and 0 close parentheses
        backtrack(result, "", 0, 0, n);
        return result;
    }
};
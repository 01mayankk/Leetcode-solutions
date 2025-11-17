class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> bracketMap = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            if (bracketMap.count(c) == 0) {
                stack.push(c);
            } else {
                if (stack.empty() || stack.top() != bracketMap[c]) {
                    return false;
                }
                stack.pop();
            }
        }

        return stack.empty();
    }
};

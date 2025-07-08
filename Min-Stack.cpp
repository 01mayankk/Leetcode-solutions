class MinStack {
    stack<int> s1;
    stack<int> minStack;
public:
    MinStack() {
        
    }

    void push(int val) {
        s1.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (s1.top() == minStack.top()) {
            minStack.pop();
        }
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return minStack.top();
    }
};

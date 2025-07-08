class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;

        for (const string& op : operations) {
            if (op == "+") {
                if (s.size() >= 2) {
                    int top1 = s.top(); s.pop();
                    int top2 = s.top();
                    s.push(top1);
                    s.push(top1 + top2);
                }
            }
            else if (op == "D") {
                if (!s.empty()) {
                    s.push(2 * s.top());
                }
            }
            else if (op == "C") {
                if (!s.empty()) {
                    s.pop();
                }
            }
            else {
                
                s.push(stoi(op));
            }
        }

        int sum = 0;
        while (!s.empty()) {
            sum += s.top();
            s.pop();
        }

        return sum;
    }
};

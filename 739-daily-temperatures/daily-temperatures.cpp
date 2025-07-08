class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> res(size, 0); 
        stack<int> s; 

        for (int i = size - 1; i >= 0; i--) {
            
            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }

            
            if (!s.empty()) {
                res[i] = s.top() - i;
            }

            
            s.push(i);
        }

        return res;
    }
};

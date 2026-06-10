class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> operations;
        int j = 0; // Pointer for target array
        
        // Read numbers from stream 1 to n
        for (int i = 1; i <= n && j < target.size(); i++) {
            
            // Every number read from stream must be pushed
            operations.push_back("Push");
            
            if (i == target[j]) {
                // Required number, keep it in stack
                j++;
            } else {
                // Not required, remove it immediately
                operations.push_back("Pop");
            }
        }
        
        return operations;
    }
};
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        
        // To store final answer
        vector<int> ans(n);
        
        // Since values are from 1 to n
        // freq[x] tells how many times x has appeared so far
        // in both arrays combined
        vector<int> freq(n + 1, 0);
        
        int common = 0;
        
        for (int i = 0; i < n; i++) {
            
            // Add current element from A
            freq[A[i]]++;
            
            // If frequency becomes 2,
            // it means this number appeared in both arrays
            if (freq[A[i]] == 2)
                common++;
            
            // Add current element from B
            freq[B[i]]++;
            
            // Again check if it became common
            if (freq[B[i]] == 2)
                common++;
            
            // Store count of common elements till index i
            ans[i] = common;
        }
        
        return ans;
    }
};
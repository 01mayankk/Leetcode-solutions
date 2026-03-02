class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        // Step 1: Count trailing zeros in each row
        vector<int> trailing(n, 0);
        
        for(int i = 0; i < n; i++) {
            int count = 0;
            
            // Traverse from right to left
            for(int j = n - 1; j >= 0; j--) {
                if(grid[i][j] == 0)
                    count++;
                else
                    break;  // stop when first '1' appears
            }
            
            trailing[i] = count;
        }
        
        int swaps = 0;
        
        // Step 2: Fix each row position
        for(int i = 0; i < n; i++) {
            
            int required = n - i - 1;  // minimum trailing zeros needed
            int j = i;
            
            // Step 3: Find valid row below i
            while(j < n && trailing[j] < required)
                j++;
            
            // If no valid row found
            if(j == n)
                return -1;
            
            // Step 4: Bring row to position i by swapping upwards
            while(j > i) {
                swap(trailing[j], trailing[j - 1]);
                swaps++;
                j--;
            }
        }
        
        return swaps;
    }
};
class Solution {
public:
    int minimumPushes(string word) {
        int pushes = 0;
        int n = word.length();
        
        // Iterate through each character in the word based on its index
        // Since all letters are distinct, we greedily assign them to the 8 available keys (2-9)
        for (int i = 0; i < n; i++) {
            // The first 8 characters take 1 push: (0 to 7) / 8 + 1 = 1
            // The next 8 characters take 2 pushes: (8 to 15) / 8 + 1 = 2
            // The next 8 characters take 3 pushes: (16 to 23) / 8 + 1 = 3
            // The remaining characters take 4 pushes
            pushes += (i / 8) + 1;
        }
        
        return pushes;
    }
};
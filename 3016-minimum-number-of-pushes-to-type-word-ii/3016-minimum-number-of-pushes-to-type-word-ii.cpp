class Solution {
public:
    int minimumPushes(string word) {
        // Array to store the frequency of each lowercase English letter
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        
        // Sort the frequencies in descending order so we can assign
        // the most frequent characters to the fewest pushes
        sort(freq.rbegin(), freq.rend());
        
        int totalPushes = 0;
        
        // Iterate through the sorted frequencies
        for (int i = 0; i < 26; i++) {
            // If the frequency is 0, there are no more characters to process
            if (freq[i] == 0) break;
            
            // The first 8 characters (index 0-7) take 1 push.
            // The next 8 characters (index 8-15) take 2 pushes, and so on.
            int pushesNeeded = (i / 8) + 1;
            
            // Add the total cost for this character
            totalPushes += freq[i] * pushesNeeded;
        }
        
        return totalPushes;
    }
};
class Solution {
public:
    
    // Backtracking function to generate happy strings
    void solve(int n, string &current, vector<string> &result) {
        
        // If the current string length becomes n, store it
        if (current.size() == n) {
            result.push_back(current);
            return;
        }

        // Try adding characters 'a', 'b', 'c'
        for (char ch = 'a'; ch <= 'c'; ch++) {

            // If current string is empty OR
            // last character is not equal to the current character
            if (current.empty() || current.back() != ch) {

                // Choose the character
                current.push_back(ch);

                // Recurse for next position
                solve(n, current, result);

                // Backtrack (remove last character)
                current.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        
        vector<string> result;
        string current = "";

        // Generate all happy strings
        solve(n, current, result);

        // If k exceeds total number of happy strings, return empty
        if (k > result.size())
            return "";

        // Return k-th string (index k-1 because of 0 indexing)
        return result[k - 1];
    }
};
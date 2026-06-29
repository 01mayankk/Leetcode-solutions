class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        // Stores the number of patterns that appear in 'word'
        int count = 0;

        // Traverse every pattern
        for (const string &pattern : patterns) {

            // string::find() returns the starting index of the substring
            // If the substring is not found, it returns string::npos
            if (word.find(pattern) != string::npos) {
                count++;
            }
        }

        return count;
    }
};
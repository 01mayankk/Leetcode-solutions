class Solution {
public:
    // Helper function to check if two strings differ by at most 2 characters
    bool isValid(string &a, string &b) {
        int diff = 0;  // counter to track number of differing characters

        // Traverse both strings character by character
        // (Given: all words are of same length)
        for (int i = 0; i < a.size(); i++) {

            // If characters at same position are different
            if (a[i] != b[i]) {
                diff++;  // increment difference count

                // If differences exceed 2, no need to continue
                if (diff > 2) return false;  // early exit (optimization)
            }
        }

        // If we reach here, differences are <= 2 → valid
        return true;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;  // stores final valid queries

        // Iterate over each query word
        for (auto &q : queries) {

            // Compare current query with every dictionary word
            for (auto &d : dictionary) {

                // Check if query and dictionary word differ by at most 2 chars
                if (isValid(q, d)) {

                    // If yes, add query to result
                    result.push_back(q);

                    // Stop checking further dictionary words for this query
                    // because we only need one valid match
                    break;
                }
            }
        }

        // Return all valid queries
        return result;
    }
};
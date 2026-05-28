class Solution {

    // Trie Node structure
    struct TrieNode {

        // Stores index of child nodes
        // -1 means child does not exist
        int children[26];

        // Stores shortest word length
        int bestLen;

        // Stores index of best matching word
        int bestIdx;

        // Constructor
        TrieNode() {

            // Initially all children absent
            fill(begin(children), end(children), -1);

            // Initialize with very large values
            bestLen = INT_MAX;
            bestIdx = INT_MAX;
        }
    };

public:

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        // Trie stored as vector
        // More memory efficient than pointers
        vector<TrieNode> trie;

        // Create root node
        trie.emplace_back();

        // Insert all container words
        for(int i = 0; i < wordsContainer.size(); i++) {

            string &word = wordsContainer[i];

            int n = word.size();

            // Start from root
            int curr = 0;

            // Update root answer
            // Handles no matching suffix case
            if(n < trie[curr].bestLen ||
              (n == trie[curr].bestLen && i < trie[curr].bestIdx)) {

                trie[curr].bestLen = n;
                trie[curr].bestIdx = i;
            }

            // Insert word in reverse order
            // because we need suffix matching
            for(int j = n - 1; j >= 0; j--) {

                int ch = word[j] - 'a';

                // Create node if absent
                if(trie[curr].children[ch] == -1) {

                    // Store new node index
                    trie[curr].children[ch] = trie.size();

                    // Add new Trie node
                    trie.emplace_back();
                }

                // Move to child node
                curr = trie[curr].children[ch];

                // Update best answer at current node
                if(n < trie[curr].bestLen ||
                  (n == trie[curr].bestLen && i < trie[curr].bestIdx)) {

                    trie[curr].bestLen = n;
                    trie[curr].bestIdx = i;
                }
            }
        }

        vector<int> ans;

        // Process all queries
        for(string &query : wordsQuery) {

            int curr = 0;

            int n = query.size();

            // Traverse query in reverse
            for(int j = n - 1; j >= 0; j--) {

                int ch = query[j] - 'a';

                // Stop if suffix path breaks
                if(trie[curr].children[ch] == -1) {
                    break;
                }

                // Move to matching child
                curr = trie[curr].children[ch];
            }

            // Store answer
            ans.push_back(trie[curr].bestIdx);
        }

        // Return final result
        return ans;
    }
};
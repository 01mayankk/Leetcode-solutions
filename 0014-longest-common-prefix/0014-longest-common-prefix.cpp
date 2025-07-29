class TrieNode {
public:
    TrieNode* children[26];  // Array of pointers to children nodes for each lowercase letter
    bool end_of_word;        // Flag to indicate if a word ends at this node

    TrieNode() {
        end_of_word = false; // Initialize end_of_word as false
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;  // Initialize all children as null
        }
    }
};

class Solution {
private:
    TrieNode* root;  // Root of the Trie

public:
    Solution() {
        root = new TrieNode();  // Initialize the root node
    }

    // Insert a word into the Trie
    void insertIntoTrie(const string& word) {
        TrieNode* temp = root;
        for (char ch : word) {
            int index = ch - 'a';  // Map character to index 0-25
            // If child node doesn't exist, create a new node
            if (temp->children[index] == nullptr) {
                temp->children[index] = new TrieNode();
            }
            // Move down to the child node
            temp = temp->children[index];
        }
        temp->end_of_word = true;  // Mark the end of the word
    }

    // Traverse the Trie to find the longest common prefix (LCP)
    string getLongestCommonPrefix() {
        TrieNode* node = root;
        string prefix = "";

        while (true) {
            int childCount = 0;    // Count how many children the current node has
            int childIndex = -1;   // Store index of the one child (if exists)

            // Count the children of the current node
            for (int i = 0; i < 26; ++i) {
                if (node->children[i]) {
                    childCount++;
                    childIndex = i;
                }
            }

            // If there is more than one child or this node marks the end of a word,
            // then the common prefix cannot be extended further
            if (childCount != 1 || node->end_of_word)
                break;

            // Move to the single child node and append the corresponding character
            node = node->children[childIndex];
            prefix += (childIndex + 'a');
        }

        return prefix;
    }


    // Main function to find the longest common prefix in the vector of strings
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return ""; // If input list is empty, return empty string

        // Insert all words into the Trie
        for (const string& word : strs) {
            if (word.empty())
                return ""; // If any word is empty, LCP is empty string
            insertIntoTrie(word);
        }

        // After building Trie, find the longest common prefix by traversing it
        return getLongestCommonPrefix();
    }
};

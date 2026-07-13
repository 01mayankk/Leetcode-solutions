/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    // Helper DFS function that returns the maximum depth
    // of the subtree rooted at 'root'.
    int dfs(Node* root)
    {
        // Stores the maximum depth among all children
        int max_child_depth = 0;

        // Traverse every child of the current node
        for (Node* child : root->children)
        {
            // Recursively calculate the depth of each child
            // and keep track of the maximum depth found.
            max_child_depth = max(max_child_depth, dfs(child));
        }

        // Add 1 to include the current node itself.
        return max_child_depth + 1;
    }

    int maxDepth(Node* root)
    {
        // Handle the empty tree case.
        if (root == nullptr)
        {
            return 0;
        }

        // Start DFS from the root and return the result.
        return dfs(root);
    }
};
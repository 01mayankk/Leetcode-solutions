/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to perform preorder traversal and count nodes
    void preOrder(TreeNode* root, int& count)
    {
        // Base condition: if root is not null, process the node
        if (root)
        {
            count++; // Increment count for current node

            // Recursively count nodes in the left subtree
            preOrder(root->left, count);

            // Recursively count nodes in the right subtree
            preOrder(root->right, count);
        }
        // If root is null, recursion simply returns (no action)
    }

    // Main function to count total nodes in the binary tree
    int countNodes(TreeNode* root) {
        int count = 0; // Initialize count to zero

        // If the tree is empty, return 0
        if (root == nullptr)
        {
            return 0;
        }

        // Perform preorder traversal to count nodes
        preOrder(root, count);

        // Return total count
        return count;
    }
};
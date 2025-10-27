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

    // Helper function for inorder traversal (Left -> Root -> Right)
    void inOrder(TreeNode* root, vector<int>& result)
    {
        // Base condition: if the current node is null, stop recursion
        if (!root)
            return;

        // 1️⃣ Traverse the left subtree
        inOrder(root->left, result);

        // 2️⃣ Visit the current node (root)
        result.push_back(root->val);

        // 3️⃣ Traverse the right subtree
        inOrder(root->right, result);
    }

    // Function to find the k-th smallest element in a Binary Search Tree (BST)
    int kthSmallest(TreeNode* root, int k) {
        
        // This vector will store all node values in sorted order (due to inorder traversal)
        vector<int> result;

        // Perform inorder traversal to fill 'result'
        inOrder(root, result);

        // Since inorder of BST gives sorted order,
        // the k-th smallest element is at index (k - 1)
        return result[k - 1];
    }
};
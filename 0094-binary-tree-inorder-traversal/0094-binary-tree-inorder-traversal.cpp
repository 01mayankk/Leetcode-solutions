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

    // Helper function to perform Inorder Traversal
    // It takes:
    // 1. root -> current node of the binary tree
    // 2. result -> reference to vector where traversal result is stored
    void inOrder(TreeNode* root, vector<int>& result)
    {
        // Base Case:
        // If the current node is NULL, simply return
        if(root != nullptr)
        {
            // 1️⃣ Traverse Left Subtree
            inOrder(root->left, result);

            // 2️⃣ Process Current Node
            result.push_back(root->val);

            // 3️⃣ Traverse Right Subtree
            inOrder(root->right, result);
        }
    }

    // Main function called by LeetCode
    vector<int> inorderTraversal(TreeNode* root) {
        
        // Vector to store inorder traversal result
        vector<int> result;

        // Call helper function
        inOrder(root, result);

        // Return final inorder sequence
        return result;
    }
};

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

    int maxDepth(TreeNode* root) {
        
        // Base Case:
        // If the node is null, depth is 0
        if(root == nullptr)
        {
            return 0;
        }

        // Recursively calculate depth of left subtree
        int leftDepth = maxDepth(root->left);

        // Recursively calculate depth of right subtree
        int rightDepth = maxDepth(root->right);

        // Current node contributes +1 to the maximum depth
        // Return 1 + maximum of left and right subtree depth
        return 1 + max(leftDepth, rightDepth);
    }
};
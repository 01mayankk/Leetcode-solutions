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
    
    int diameter = 0;  // Stores final diameter
    
    int height(TreeNode* root)
    {
        // Base case
        if(root == nullptr)
            return 0;
        
        // Get height of left subtree
        int leftHeight = height(root->left);
        
        // Get height of right subtree
        int rightHeight = height(root->right);
        
        // Update diameter
        diameter = max(diameter, leftHeight + rightHeight);
        
        // Return height of current node
        return 1 + max(leftHeight, rightHeight);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};
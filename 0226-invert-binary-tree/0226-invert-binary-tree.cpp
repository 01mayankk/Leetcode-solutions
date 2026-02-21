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
    TreeNode* invertTree(TreeNode* root) {
        
        // Base Case:
        // If the current node is NULL, simply return NULL
        if(root == nullptr)
        {
            return nullptr;
        }

        // Swap left and right child pointers
        TreeNode* temp = root->right;  // Store right child temporarily
        root->right = root->left;      // Move left child to right
        root->left = temp;             // Assign stored right child to left

        // Recursively invert the right subtree
        invertTree(root->right);

        // Recursively invert the left subtree
        invertTree(root->left);

        // Return the root of the inverted subtree
        return root;
    }
};
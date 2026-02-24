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
    
    // Helper function for DFS traversal
    int solve(TreeNode* root, int currentSum) {
        
        // Base condition: if node is NULL, return 0
        if(root == NULL)
            return 0;
        
        // Update currentSum:
        // Multiply by 2 (shift left in binary)
        // Add current node's value (0 or 1)
        currentSum = currentSum * 2 + root->val;
        
        // If leaf node, return the calculated binary number
        if(root->left == NULL && root->right == NULL)
            return currentSum;
        
        // Recursively calculate sum from left and right subtree
        int leftSum = solve(root->left, currentSum);
        int rightSum = solve(root->right, currentSum);
        
        // Return total sum from both sides
        return leftSum + rightSum;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);  // Start DFS with sum = 0
    }
};
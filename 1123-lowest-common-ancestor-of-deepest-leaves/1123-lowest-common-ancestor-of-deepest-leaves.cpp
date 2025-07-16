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
    // Helper function returns a pair: {depth, LCA node}
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) return {0, nullptr};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int leftDepth = left.first;
        int rightDepth = right.first;

        // If depths are equal, this root is the LCA of deepest leaves
        if (leftDepth == rightDepth) {
            return {leftDepth + 1, root};
        } 
        // Else return deeper subtree's result
        else if (leftDepth > rightDepth) {
            return {leftDepth + 1, left.second};
        } else {
            return {rightDepth + 1, right.second};
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
};

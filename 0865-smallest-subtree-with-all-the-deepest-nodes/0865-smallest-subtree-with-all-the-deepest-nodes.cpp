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

    // Helper function returns:
    // {maximum depth from this node, subtree root containing all deepest nodes}
    pair<int, TreeNode*> dfs(TreeNode* root) {

        // Base case: empty tree
        if (!root) {
            return {0, nullptr};
        }

        // Postorder traversal: left and right
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // If left subtree is deeper
        if (left.first > right.first) {
            return {left.first + 1, left.second};
        }

        // If right subtree is deeper
        if (right.first > left.first) {
            return {right.first + 1, right.second};
        }

        // If both depths are equal:
        // current node is the Lowest Common Ancestor
        return {left.first + 1, root};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};

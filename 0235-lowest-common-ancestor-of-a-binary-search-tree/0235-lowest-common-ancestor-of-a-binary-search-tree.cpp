/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            // If both nodes are smaller, move to the left subtree
            if (root->val > p->val && root->val > q->val)
                root = root->left;

            // If both nodes are larger, move to the right subtree
            else if (root->val < p->val && root->val < q->val)
                root = root->right;

            // Otherwise, this is the split point → LCA found
            else
                return root;
        }
        return nullptr;
    }
};

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

    void traversal(TreeNode* p, TreeNode* q, bool& result)
    {
        // If both are null → this subtree is same
        if(p == nullptr && q == nullptr)
            return;

        // If one is null → not same
        if(p == nullptr || q == nullptr)
        {
            result = false;
            return;
        }

        // If values are different
        if(p->val != q->val)
        {
            result = false;
            return;
        }

        // Recursively check left and right
        traversal(p->left, q->left, result);
        traversal(p->right, q->right, result);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        bool result = true;   // assume true initially
        traversal(p, q, result);

        return result;
    }
};
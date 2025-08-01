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

    void preOrder(TreeNode* root)
    {

    }
    TreeNode* searchBST(TreeNode* root, int val) {
        vector<int>result;
        if(root == nullptr)
        {
            return nullptr;
        }

        if(root -> val == val)
        {
            
            return root;

        }
        if(val < root -> val)
        {
            return searchBST(root -> left, val);
        }
        if(val > root -> val)
        {
            return searchBST(root -> right, val);
        }

        return NULL;
    }
};
class Solution {
public:
    vector<TreeNode*> v;

    // Inorder traversal to collect nodes
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        v.push_back(root);
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        // Step 1: Extract values from nodes
        vector<int> vals;
        for (TreeNode* node : v) {
            vals.push_back(node->val);
        }

        // Step 2: Sort the values
        sort(vals.begin(), vals.end());

        // Step 3: Assign back the sorted values to the nodes
        for (int i = 0; i < v.size(); ++i) {
            v[i]->val = vals[i];
        }
    }
};

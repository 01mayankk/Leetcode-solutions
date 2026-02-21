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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        // This will store the final level order traversal result
        vector<vector<int>> result;

        // Base case: if tree is empty, return empty result
        if(root == nullptr)
        {
            return {};
        }

        // Queue is used for BFS (Level Order Traversal)
        queue<TreeNode*> q;

        // Start by pushing the root node into queue
        q.push(root);

        // Continue traversal until queue becomes empty
        while(!q.empty())
        {
            // Number of nodes at current level
            int len = q.size();

            // This vector will store values of current level
            vector<int> ans;

            // Process all nodes of current level
            while(len--)
            {
                // Get the front node of queue
                TreeNode* temp = q.front();

                // Remove it from queue (very important in BFS)
                q.pop();

                // Store its value in current level vector
                ans.push_back(temp->val);

                // If left child exists, push it into queue
                if(temp->left)
                {
                    q.push(temp->left);
                }

                // If right child exists, push it into queue
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }

            // After finishing one level, add it to result
            result.push_back(ans);
        }

        // Return final 2D vector containing level order traversal
        return result;
    }
};
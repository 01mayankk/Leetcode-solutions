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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        // This will store the final zigzag traversal
        vector<vector<int>> result;

        // Base case: if tree is empty, return empty result
        if(root == nullptr)
        {
            return {};
        }

        // Queue for performing BFS (level order traversal)
        queue<TreeNode*> q;
        q.push(root);  // Start by pushing root node

        // Flag to decide traversal direction
        // true  -> left to right
        // false -> right to left
        bool leftToRight = true;

        // Continue until all nodes are processed
        while(!q.empty())
        {
            // Number of nodes in the current level
            int len = q.size();

            // This vector will store current level values
            vector<int> ans;

            // Process all nodes of this level
            while(len--)
            {
                // Get front node of queue
                TreeNode* temp = q.front();
                q.pop();  // Remove it from queue

                // Store node value
                ans.push_back(temp->val);

                // Push left child into queue (if exists)
                if(temp->left)
                {
                    q.push(temp->left);
                }

                // Push right child into queue (if exists)
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }

            // If direction is right-to-left,
            // reverse the current level before adding to result
            if(!leftToRight)
            {
                reverse(ans.begin(), ans.end());
            }

            // Store current level in final result
            result.push_back(ans);

            // Toggle direction for next level
            leftToRight = !leftToRight;
        }

        // Return final zigzag traversal
        return result;
    }
};
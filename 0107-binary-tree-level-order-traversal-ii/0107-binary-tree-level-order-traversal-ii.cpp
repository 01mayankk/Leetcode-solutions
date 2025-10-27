class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // This will store the final result (list of levels from bottom to top)
        vector<vector<int>> result;

        // If the tree is empty, just return an empty result
        if (!root) return result;

        // Use a queue for level-order (BFS) traversal
        queue<TreeNode*> q;
        q.push(root); // Start from the root node

        // Continue until all nodes are processed
        while (!q.empty()) {

            // Get the number of nodes in the current level
            int size = q.size();

            // This vector will store all nodes' values for the current level
            vector<int> level;

            // Process each node in the current level
            for (int i = 0; i < size; i++) {
                // Get the front node from the queue
                TreeNode* node = q.front();
                q.pop();

                // Store its value in the current level vector
                level.push_back(node->val);

                // Add left and right children (if exist) to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Add the current level (from top to bottom order)
            result.push_back(level);
        }

        // Reverse the order to make it bottom-to-top
        reverse(result.begin(), result.end());

        // Return the bottom-up level order traversal
        return result;
    }
};

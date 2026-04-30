class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        // Result vector to store average of each level
        vector<double> avg;

        // Edge case: if tree is empty
        if (root == nullptr) return {};

        // Queue for BFS (level-order traversal)
        queue<TreeNode*> q;
        q.push(root);

        // Traverse until all levels are processed
        while (!q.empty()) {
            
            // Number of nodes at current level
            int len = q.size();

            // Variable to store sum of current level
            double sum = 0;

            // Process all nodes of current level
            for (int i = 0; i < len; i++) {
                
                // Get front node and remove it
                TreeNode* node = q.front();
                q.pop();

                // Add node value to sum
                sum += node->val;

                // Push left child if exists
                if (node->left) q.push(node->left);

                // Push right child if exists
                if (node->right) q.push(node->right);
            }

            // Compute average of current level and store it
            avg.push_back(sum / len);
        }

        // Return final result
        return avg;
    }
};
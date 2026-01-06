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

// class Solution {
// public:
//     int maxLevelSum(TreeNode* root) {

//         if (!root) return 0;

//         // Queue for level order traversal
//         queue<TreeNode*> q;
//         q.push(root);

//         // HashMap to store: level -> sum of that level
//         unordered_map<int, long long> levelSum;

//         int level = 1;  // Root is at level 1

//         // Perform BFS
//         while (!q.empty()) {

//             int size = q.size();    // Number of nodes at current level
//             long long sum = 0;

//             // Process all nodes of current level
//             for (int i = 0; i < size; i++) {
//                 TreeNode* node = q.front();
//                 q.pop();

//                 sum += node->val;   // Add node value to current level sum

//                 // Push children for next level
//                 if (node->left)  q.push(node->left);
//                 if (node->right) q.push(node->right);
//             }

//             // Store sum for this level in hashmap
//             levelSum[level] = sum;

//             level++;  // Move to next level
//         }

//         // Traverse hashmap to find level with maximum sum
//         int ansLevel = 1;
//         long long maxSum = LLONG_MIN;

//         for (auto &it : levelSum) {
//             if (it.second > maxSum) {
//                 maxSum = it.second;
//                 ansLevel = it.first;
//             }
//         }

//         return ansLevel;
//     }
// };

class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        // Safety check: If tree is empty, no levels exist
        if (!root) return 0;

        // Queue for Breadth-First Search (Level Order Traversal)
        queue<TreeNode*> q;

        // Start BFS from root node (level 1)
        q.push(root);

        int level = 1;          // Tracks current level number (1-indexed)
        int ansLevel = 1;       // Stores level having maximum sum
        long long maxSum = LLONG_MIN; 
        // Initialize to minimum possible value because node values can be negative

        // Continue BFS until all levels are processed
        while (!q.empty()) {

            // Number of nodes present at current level
            int size = q.size();

            // Sum of node values at current level
            long long levelSum = 0;

            // Process all nodes belonging to this level
            for (int i = 0; i < size; i++) {

                // Get the front node from queue
                TreeNode* node = q.front();
                q.pop();

                // Add current node's value to the level sum
                levelSum += node->val;

                // Push left child (next level) if it exists
                if (node->left)
                    q.push(node->left);

                // Push right child (next level) if it exists
                if (node->right)
                    q.push(node->right);
            }

            // After finishing one level:
            // Compare current level sum with maximum sum found so far
            if (levelSum > maxSum) {
                maxSum = levelSum;   // Update maximum sum
                ansLevel = level;    // Update answer level
            }

            // Move to next level
            level++;
        }

        // Return the smallest level having the maximum sum
        return ansLevel;
    }
};

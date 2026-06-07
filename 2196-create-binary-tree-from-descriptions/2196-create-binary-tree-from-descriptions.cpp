/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        // Maps node value -> TreeNode pointer
        unordered_map<int, TreeNode*> nodes;

        // Stores all nodes that appear as a child
        unordered_set<int> children;

        for (auto &d : descriptions) {
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            // Create parent node if it doesn't exist
            if (nodes.find(parent) == nodes.end()) {
                nodes[parent] = new TreeNode(parent);
            }

            // Create child node if it doesn't exist
            if (nodes.find(child) == nodes.end()) {
                nodes[child] = new TreeNode(child);
            }

            // Connect child to parent
            if (isLeft == 1) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }

            // Mark this node as a child
            children.insert(child);
        }

        // Root is the node that never appeared as a child
        for (auto &p : nodes) {
            if (children.find(p.first) == children.end()) {
                return p.second;
            }
        }

        return nullptr;
    }
};
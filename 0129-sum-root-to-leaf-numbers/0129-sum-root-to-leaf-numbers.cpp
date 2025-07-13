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
private:
    void findPath(TreeNode* root, vector<vector<int>>& ans, vector<int>& currPath){
        currPath.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(currPath);
        }
        if(root->left!=NULL){
            findPath(root->left, ans, currPath);
        }
        if(root->right!=NULL){
            findPath(root->right,ans,currPath);
        }
        currPath.pop_back();
    }

    int findSum(vector<vector<int>> ans){
        int sum = 0;
        int size = ans.size();

        for(int i=0; i<size; i++){
            vector<int> currPath = ans[i];
            int currPathLength = currPath.size();
            // cout<<currPathLength<<endl;
            int currPathSum = 0;
            // cout<<"Current vector array"<<endl;
            for(int j=0; j<currPathLength; j++){
                // cout<<ans[i][j]<<" ";
                currPathSum += currPath[j]*pow(10,currPathLength - j - 1);
            }
            // cout<<endl;
            // cout<<currPathSum<<endl;
            sum += currPathSum;
        }
        return sum;
    }

public:
    int sumNumbers(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> currPath;
        findPath(root, ans, currPath);
        int sum = findSum(ans);
        return sum;
    }
};
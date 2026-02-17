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
    void  traverse(TreeNode* root,int target,int sum,vector<int> &path,vector < vector < int >> &ans){
        if (root==nullptr){
            return;
        }
        sum+=root->val;
        path.push_back(root->val);
        if (root->left==nullptr && root->right==nullptr){
            if (sum==target){
                ans.push_back(path);
            }
        }
        traverse(root->left,target,sum,path,ans);
        traverse(root->right,target,sum,path,ans);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector < vector < int>> ans;
        vector <int> path;
        traverse(root,targetSum,0,path,ans);
        return ans;
    }
};
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
    void traverse(TreeNode* root,vector <int>&ans){
        if (root==nullptr){
            return;
        }
        traverse(root->left,ans);
        ans.push_back(root->val);
        traverse(root->right,ans);
    }
    vector<int> findMode(TreeNode* root) {
        vector <int> ans;
        traverse(root,ans);
        unordered_map<int,int>mp;
        for (auto &p:ans){
            mp[p]++;
        }
        int gmax = 0;
        for (auto &p:mp){
            if (p.second>gmax){
                gmax = p.second;
            }
        }
        vector <int> res;
        for (auto &p:mp){
            if (p.second==gmax){
                res.push_back(p.first);
            }
        }
        return res;
    }
};
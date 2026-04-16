/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(TreeNode* root,int pd,int qd){
        if (root==nullptr){
            return nullptr;
        }
        if (root->val>pd && root->val>qd){
            return solve(root->left,pd,qd);
        }
        if (root->val<pd && root->val<qd){
            return solve(root->right,pd,qd);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p->val,q->val);
    }
};
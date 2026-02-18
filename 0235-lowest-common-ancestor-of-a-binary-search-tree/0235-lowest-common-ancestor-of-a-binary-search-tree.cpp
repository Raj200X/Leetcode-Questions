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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int r = root->val;
        if (p->val<r && q->val>r){
            return root;
        }
        if (p->val<r && q->val<r){
            return lowestCommonAncestor(root->left,p,q);
        }
        if (p->val>r && q->val>r){
            return lowestCommonAncestor(root->right,p,q);;
        }
        
        return root;
    }
};
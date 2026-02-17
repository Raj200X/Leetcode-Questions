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
    void traverse(TreeNode* root,int target,int sum,bool &check){
        if (root==nullptr){
            return;
        }
        sum+=root->val;
        if (root->left==nullptr && root->right==nullptr){
            if (sum==target){
                check =  true;
                return;
            }
        }
        traverse(root->left,target,sum,check);
        traverse(root->right,target,sum,check);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = false;
        traverse(root,targetSum,sum,ans);

   

        return ans;

    }
};
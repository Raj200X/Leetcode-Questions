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
    int sum = 0;
    void inorder(TreeNode* root,int currNum){
        if (root==nullptr) return;
        inorder(root->left,currNum*10+root->val);
        if (root->left==nullptr && root->right==nullptr) sum+=currNum*10+root->val;
        inorder(root->right,currNum*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        inorder(root,0);
        return sum;

    }
};
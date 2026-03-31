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
    // int sum = 0;
    // void inorder(TreeNode* root,int currNum){
    //     if (root==nullptr) return;
    //     inorder(root->left,currNum*10+root->val);
    //     if (root->left==nullptr && root->right==nullptr) sum+=currNum*10+root->val;
    //     inorder(root->right,currNum*10+root->val);
    // }
    int sumNumbers(TreeNode* root) {
        // inorder(root,0);
        // return sum;
        queue<TreeNode*>q;
        q.push(root);
        queue<int>nums;
        nums.push(root->val);
        int sum =0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            int currSum = nums.front();
            nums.pop();
            if (temp->left) {
                q.push(temp->left);
                nums.push(currSum*10+temp->left->val);
            }
            if (temp->right) {
                q.push(temp->right);
                nums.push(currSum*10+temp->right->val);
            }
            if (temp->left==nullptr && temp->right==nullptr){
                sum+=currSum;
            }
        }
        return sum;

    }
};
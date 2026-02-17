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

    int getMax(TreeNode* root){
        if (root==nullptr){
            return -1;
        }
        while (root->right!=nullptr){
            root = root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==nullptr){
            return nullptr;
        }
        if (root->val==key){
            // if left and right both child is not present
            if (root->left==nullptr && root->right==nullptr){
                delete root;
                return nullptr;
            }
            // if left child exist but not right child
            if (root->left!=nullptr && root->right==nullptr){
                TreeNode* leftChild = root->left;
                root->left = nullptr;
                delete root;
                return leftChild;
            }
            if (root->left==nullptr && root->right!=nullptr){
                TreeNode* rightChild = root->right;
                root->right = nullptr;
                delete root;
                return rightChild;
            }
            if (root->left!=nullptr && root->right!=nullptr){
                int maxVal = getMax(root->left);
                root->val = maxVal;
                root->left = deleteNode(root->left,maxVal);
                return root;
            }

        }
        else{
            if (root->val>key){
                root->left = deleteNode(root->left,key);
            }
            else{
               root->right =  deleteNode(root->right,key);
            }
        }
        return root;
    }
};
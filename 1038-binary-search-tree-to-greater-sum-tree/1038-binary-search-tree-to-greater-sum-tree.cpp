/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    vector<int> elements;
    int i = 0;
    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        traverse(root->left);
        elements.push_back(root->val);
        sum += root->val;
        traverse(root->right);
    }
    void prefixArray(vector<int>& prefix,int n){
        prefix[0] = elements[0];
        for (int i = 1;i<n;i++){
            prefix[i] = prefix[i-1] + elements[i];
        }
    }
    void updateInorder(TreeNode* root,int sum,vector<int>&prefix){
        if (root==nullptr){
            return;
        }
        updateInorder(root->left,sum,prefix);
         if (i==0){
            root->val = sum;
        }
        else{
            root->val = sum - prefix[i-1];
        }
        i++;
        updateInorder(root->right,sum,prefix);
    }

    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        int n = elements.size();
        vector<int>prefix(n,0);
        prefixArray(prefix,n);
        updateInorder(root,sum,prefix);
        return root;
    }
};
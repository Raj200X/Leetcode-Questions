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
   void isValid(TreeNode* root, TreeNode* &prev, bool &ans) {
    if (root == nullptr) return;

    isValid(root->left, prev, ans);

    if (prev != nullptr && root->val <= prev->val) {
        ans = false;
        return;
    }

    prev = root;

    isValid(root->right, prev, ans);
   }

    bool isValidBST(TreeNode* root) {
        bool ans = true;
        TreeNode* prev = nullptr;
      isValid(root,prev,ans);
        return ans;
    }
};

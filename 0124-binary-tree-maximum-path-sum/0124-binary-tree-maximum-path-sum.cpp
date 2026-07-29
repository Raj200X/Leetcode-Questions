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
    int ans = INT_MIN;
    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        left = max(0, left);
        right = max(0, right);
        ans = max(ans, root->val + (left + right));
        return root->val + max(left, right);;
    }
    int maxPathSum(TreeNode* root) {
        height(root);
        return ans;
    }
};
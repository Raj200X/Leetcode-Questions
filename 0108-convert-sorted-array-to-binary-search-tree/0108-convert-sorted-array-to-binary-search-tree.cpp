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
    TreeNode* construct(vector<int>& nums, int s, int e) {
        if (s > e) {
            return nullptr;
        }
        int middle = (s + e) / 2;
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = construct(nums, s, middle-1);
        root->right = construct(nums, middle + 1, e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        TreeNode* root = construct(nums, s, e);
        return root;
    }
};
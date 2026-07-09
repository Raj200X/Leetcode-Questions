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
    vector<int>inOrder;
        void traverse(TreeNode* root){
        if (root==nullptr){
            return ;
        }
        traverse(root->left);
        inOrder.push_back(root->val);
        traverse(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        traverse(root);
        for (auto p:inOrder){
            cout << p << " ";
        }
        vector<vector<int>>ans;
        for (auto q:queries){
            auto it = lower_bound(inOrder.begin(), inOrder.end(), q);
            int floor = -1;
            int ceil = -1;
            if (it == inOrder.end()) {
                floor = inOrder.back();
            }
            else if (*it == q) {
                floor = ceil = q;
            }
            else {
                ceil = *it;
                if (it != inOrder.begin()) {
                    floor = *(it - 1);
                }
            }
            ans.push_back({floor, ceil});
        }
        return ans;
    }
};
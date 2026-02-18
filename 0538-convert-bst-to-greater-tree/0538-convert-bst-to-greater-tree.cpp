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
    void StoreInorder(TreeNode* root, vector<int>& inOrder) {
        if (root == nullptr) {
            return;
        }
        StoreInorder(root->left, inOrder);
        inOrder.push_back(root->val);
        StoreInorder(root->right, inOrder);
    }
    void updateInOrder(TreeNode* root, vector<int> inOrder, int& index) {
        if (root == nullptr) {
            return;
        }
        updateInOrder(root->left, inOrder, index);
        root->val = inOrder[index++];
        updateInOrder(root->right, inOrder, index);
    }
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return root;
        }
        vector<int> inOrder;
        StoreInorder(root, inOrder);
        int n = inOrder.size();
        for (int i = n - 1; i >= 0; i--) {
            int curr = inOrder[i];
            int next = 0;
            if (i + 1 < n) {
                next = inOrder[i + 1];
            }
            int sum = curr + next;
            inOrder[i] = sum;
        }
        int index = 0;
        updateInOrder(root, inOrder, index);
        return root;
    }
};
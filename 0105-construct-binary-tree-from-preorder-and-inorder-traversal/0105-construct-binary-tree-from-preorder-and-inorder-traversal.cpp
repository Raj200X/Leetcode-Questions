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
    TreeNode* solve(int ps,int pe,vector<int> preorder,int is,int ie,vector<int> inorder){
        if (is>ie){
            return nullptr;
        }
        int idx = is;
        while (inorder[idx]!=preorder[ps]){
            idx++;
        }
        int count = idx-is;
        TreeNode* root = new TreeNode(preorder[ps]);
        root->left =solve(ps+1,ps+count,preorder,is,idx-1,inorder);
        root->right = solve(ps+count+1,pe,preorder,idx+1,ie,inorder);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int is = 0;
        int ps = 0;
        int pe = preorder.size()-1 ;
        int ie = inorder.size()-1;
        TreeNode* node = solve(ps,pe,preorder,is,ie,inorder);
        return node;
    }
};
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
    bool areEqual(vector<vector<int>>& a, vector<vector<int>>& b) {
    if (a.size() != b.size()) return false;

    for (int i = 0; i < a.size(); i++) {
        if (a[i].size() != b[i].size()) return false;

        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j] != b[i][j])
                return false;
        }
    }
    return true;
}
vector<vector<int>> bfs (TreeNode* root){
    vector<vector<int>> ans;
    if (root==nullptr){
        return ans;
    }
    queue <TreeNode*>q;
    q.push(root);
    while (!q.empty()){
        vector <int> level;
        int size = q.size();
        while (size--){
            TreeNode* temp = q.front();
            q.pop();
            if (temp) {
                level.push_back(temp->val);
                q.push(temp->left);
                q.push(temp->right);
            } else {
                level.push_back(INT_MIN); 
            }
        }
        ans.push_back(level);
    }
    return ans;
}

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<vector<int>> t1 = bfs(p);
        vector<vector<int>> t2 = bfs(q);
        return areEqual(t1,t2);
    }
};
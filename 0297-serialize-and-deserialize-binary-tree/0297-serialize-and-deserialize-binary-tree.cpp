/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    if (root == NULL) return "";   // FIX

    string ans;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        if (temp == NULL) {
            ans += "null,";
        } else {
            ans += to_string(temp->val) + ",";
            q.push(temp->left);
            q.push(temp->right);
        }
    }

    return ans;
}


    TreeNode* deserialize(string data) {
        if (data == "")
            return NULL;

        stringstream ss(data);
        string val;

        getline(ss, val, ',');
        TreeNode* root = new TreeNode(stoi(val));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* parent = q.front();
            q.pop();

            // left child
            if (!getline(ss, val, ','))
                break;
            if (val != "null" && val != "") {
                parent->left = new TreeNode(stoi(val));
                q.push(parent->left);
            }

            // right child
            if (!getline(ss, val, ','))
                break;
            if (val != "null" && val != "") {
                parent->right = new TreeNode(stoi(val));
                q.push(parent->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
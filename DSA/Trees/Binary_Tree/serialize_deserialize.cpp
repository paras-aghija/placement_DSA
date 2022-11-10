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
        if(root==NULL) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            if(node==NULL) s.append("# ");
            else s.append(to_string(node->val)+' ');
            if(node!=NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if(s.length()==0) return NULL;
        stringstream ss(s);
        string val;
        ss>>val;
        TreeNode *root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            ss>>val;
            if(val=="#") node->left = NULL;
            else {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            ss>>val;
            if(val=="#") node->right=NULL;
            else {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
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
    
    vector<int> io, po;
    map<int,int> m;
    TreeNode* build(int xp, int yp, int xi, int yi){
        if(yp<xp) return NULL;
        TreeNode *root = new TreeNode(po[xp]);
        int idx = m[po[xp]];
        int len = idx-xi;
        root->left = build(xp+1, xp+len, xi, xi+len);
        root->right = build(xp+len+1, yp,xi+len+1, yi);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        io = inorder;
        po = preorder;
        for(int i=0;i<io.size();i++){
            m[io[i]] = i;
        }
        TreeNode *root = build(0,po.size()-1, 0, io.size()-1);
        return root;
    }
};
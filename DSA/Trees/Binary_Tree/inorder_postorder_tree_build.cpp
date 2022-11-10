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
    map<int,int> m;
    vector<int> io, po;
    TreeNode *build(int x1,int y1,int x2,int y2){
        if(y1<x1) return NULL;
        TreeNode *root = new TreeNode(po[y2]);
        int idx = m[po[y2]];
        int len = y1-idx;
        root->right = build(idx+1, y1, y2-len ,y2-1);
        root->left = build(x1, idx-1, x2, y2-len-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        io = inorder;
        po = postorder;
        for(int i=0;i<io.size();i++){
            m[io[i]] = i;
        }
        TreeNode *root = build(0, io.size()-1, 0, po.size()-1);
        return root;
        
    }
};
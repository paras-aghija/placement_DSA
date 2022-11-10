/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root==p) return p;
        if(root==q) return q;
        
        TreeNode *a = lowestCommonAncestor(root->left, p, q);
        TreeNode *b = lowestCommonAncestor(root->right, p, q);
        
        if(a and b) return root;
        else if(a) return a;
        else if(b) return b;
        
        return NULL;
    }
};
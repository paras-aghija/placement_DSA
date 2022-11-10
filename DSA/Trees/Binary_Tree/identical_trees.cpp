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
    
    bool inorder(TreeNode *a, TreeNode *b){
        if(a==NULL and b==NULL) return true;
        if(a==NULL and b!=NULL) return false;
        if(a!=NULL and b==NULL) return false;
        
        bool left = inorder(a->left, b->left);
        bool curr = a->val == b->val;
        bool right = inorder(a->right, b->right);
        
        return (left & right & curr);
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return inorder(p, q);
    }
};
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
        if(a==NULL or b==NULL) return false;
        bool left = inorder(a->left, b->right);
        bool curr = a->val == b->val;
        bool right = inorder(a->right, b->left);
        
        return (left&curr&right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root->left and root->right){
            return inorder(root->left, root->right);
        }
        else if(root->left or root->right) return false;
        else return true;
    }
};
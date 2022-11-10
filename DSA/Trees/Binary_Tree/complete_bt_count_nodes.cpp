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
    
    int lheight(TreeNode *root){
        int ans=0;
        TreeNode *temp=root;
        while(temp!=NULL){
            temp=temp->left;
            ans++;
        }
        return ans;
    }
    
    int rheight(TreeNode *root){
        int ans=0;
        TreeNode *temp=root;
        while(temp!=NULL){
            temp=temp->right;
            ans++;
        }
        return ans;
    }
    
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh = lheight(root->left)+1;
        int rh = rheight(root->right)+1;
        
        if(lh==rh) return (1<<lh)-1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
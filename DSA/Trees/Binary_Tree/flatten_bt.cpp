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
    TreeNode *prev;
    
    Solution(){
        prev=NULL;
    }
    
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};

// APPROACH 2 O(1) space

class Solution {
public:
       
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode *curr=root, *prev;
        while(curr!=NULL){
            if(curr->left){
                prev=curr->left;
                while(prev->right) prev = prev->right;
                prev->right=curr->right;
                curr->right=curr->left;
            }
            curr=curr->right;
        }
    }
};

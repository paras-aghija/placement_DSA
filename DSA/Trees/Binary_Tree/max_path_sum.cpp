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
    
    pair<int,int> msum(TreeNode *root){
        if(root==NULL) return {0,INT_MIN};
        pair<int,int> a = msum(root->left);
        pair<int,int> b = msum(root->right);
        return {max(root->val, root->val + max(a.first,b.first)), max({root->val, a.second, b.second, root->val+a.first+b.first, root->val+a.first, root->val+b.first})};
    }
    
    int maxPathSum(TreeNode* root) {
        pair<int, int> ans = msum(root);
        return ans.second;
    }
};
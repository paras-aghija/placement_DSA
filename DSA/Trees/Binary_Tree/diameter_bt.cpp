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
    
    pair<int,int> solve(TreeNode *root){
        if(root==NULL) return {0,0};
        auto [la, lh] = solve(root->left);
        auto [ra, rh] = solve(root->right);
        int cd = lh+rh;
        return {max({la,ra,cd}), max(lh, rh)+1};
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        auto [ans, height] = solve(root);
        return ans;
    }
};
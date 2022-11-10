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
    
    pair<int, bool> balanced(TreeNode *root){
        if(root==NULL) return {0, true};
        auto [left, lb] = balanced(root->left);
        auto [right, rb] = balanced(root->right);
        return{ 1+max(left,right), (lb & rb & (abs(left-right)<=1))};
    }
    bool isBalanced(TreeNode* root) {
        auto [height, ans] = balanced(root);
        return ans;
    }
};
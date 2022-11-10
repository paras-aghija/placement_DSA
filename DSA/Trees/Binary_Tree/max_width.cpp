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
    
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int width = 0;
        while(!q.empty()){
            int n = q.size();
            int x = q.front().second;
            int f, l;
            for(int i=0;i<n;i++){
                auto [node, idx] = q.front();
                q.pop();
                if(i==0) f=idx;
                if(i==n-1) l=idx;
                if(node->left) q.push({node->left, 2*(idx-x)});
                if(node->right) q.push({node->right, 2*(idx-x)+1});
            }
            width = max(width, (l-f+1));
        }
        return width;
    }
};
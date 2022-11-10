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
    
    void inorder(TreeNode *root, int x, int y, map<int,map<int,multiset<int>>> &ans){
        if(root==NULL) return;
        ans[x][y].insert(root->val);
        inorder(root->left, x-1, y+1, ans);
        inorder(root->right, x+1, y+1, ans);
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> ans;
        vector<vector<int>> a;
        inorder(root, 0,0, ans);
        for(auto x : ans){
            vector<int> v;
            for(auto y : x.second){
                for(auto e : y.second){
                    v.push_back(e);
                }
            }
            a.push_back(v);
        }
        return a;
    }
};
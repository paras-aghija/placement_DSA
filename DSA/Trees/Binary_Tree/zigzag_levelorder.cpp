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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        vector<int> c;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp==NULL){
                if(c.size()==0) break; 
                if(ans.size()%2) reverse(c.begin(), c.end());
                ans.push_back(c);
                c.clear();
                q.push(NULL);
            }
            else{
                c.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};
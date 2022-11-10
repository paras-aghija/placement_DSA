/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/*
class Solution(object):
    def distanceK(self, root, target, K):
        ans = []

        # Return distance from node to target if exists, else -1
        # Vertex distance: the # of vertices on the path from node to target
        def dfs(node):
            if not node:
                return -1
            elif node is target:
                subtree_add(node, 0)
                return 1
            else:
                L, R = dfs(node.left), dfs(node.right)
                if L != -1:
                    if L == K: ans.append(node.val)
                    subtree_add(node.right, L + 1)
                    return L + 1
                elif R != -1:
                    if R == K: ans.append(node.val)
                    subtree_add(node.left, R + 1)
                    return R + 1
                else:
                    return -1

        # Add all nodes 'K - dist' from the node to answer.
        def subtree_add(node, dist):
            if not node:
                return
            elif dist == K:
                ans.append(node.val)
            else:
                subtree_add(node.left, dist + 1)
                subtree_add(node.right, dist + 1)

        dfs(root)
        return ans
*/


// MY CODE

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    TreeNode *found;
    
    void distK(TreeNode *root, int k){
        if(k<0) return;
        if(root==NULL or root==found) return;
        if(k==0){
            ans.push_back(root->val);
            return;
        } 
        distK(root->left, k-1);
        distK(root->right, k-1);
    }
    
    int dfs(TreeNode *root, TreeNode* target, int k ){
        if(root==NULL) return 0;
        if(root==target){
            if(k==0){ 
                ans.push_back(root->val);
                return 1;
            }
            distK(root->left, k-1);
            distK(root->right, k-1);
            found = root;
            return 1;
        }
        int a = dfs(root->left, target, k);
        int b = dfs(root->right, target, k);
        if(a){
            distK(root, k-a);
            found=root;
            return a+1;
        }
        if(b){
            distK(root, k-b);
            found=root;
            return b+1;
        }
        return 0;
    }    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, target, k);
        return ans;
    }
};
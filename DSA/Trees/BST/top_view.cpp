/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<map>
#include<vector>



vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    if(root==NULL) return {};
    map<int,int> m;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto curr = q.front().first;
        int x = q.front().second;
        q.pop();
        if(m.find(x)==m.end()) m[x] = curr->val;
        if(curr->left) q.push({curr->left, x-1});
        if(curr->right) q.push({curr->right, x+1});
    }
    vector<int> v;
    for(auto p : m){
        v.push_back(p.second);
    }
    return v;
}
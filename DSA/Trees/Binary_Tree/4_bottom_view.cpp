/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

     if(root==NULL) return {};
    map<int,int> m;
    queue<pair<BinaryTreeNode<int>*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto curr = q.front().first;
        int x = q.front().second;
        q.pop();
        m[x] = curr->data;
        if(curr->left) q.push({curr->left, x-1});
        if(curr->right) q.push({curr->right, x+1});
    }
    vector<int> v;
    for(auto p : m){
        v.push_back(p.second);
    }
    return v;
}

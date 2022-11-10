/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int target;
int ans = 0;
int a, b, lh, rh;
pair<int,int> dfs(BinaryTreeNode<int>* root){
    if(root==NULL) return {-1, 0};
    
    auto [a, lh] = dfs(root->left);
    auto [b, rh] = dfs(root->right);
    
    if(root->data == target){
        ans = max(ans, max(lh,rh));
        return {1, max(lh,rh)+1};
    }
    if(a==-1 and b==-1) return {-1, max(lh,rh)+1};
    if(a==-1){
        ans = max(ans, (b+lh));
        return {b+1, max(lh,rh)+1};
    } else{
        ans = max(ans, (a+rh));
        return {a+1, max(lh,rh)+1};
    }
    return {-1, 0};
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
    target = start;
    dfs(root);
    return ans;
    
}

/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

vector<int> ans;

void leftb(TreeNode<int> *root){
    if(root==NULL) return;
    if(root->left==NULL and root->right==NULL) return;
    ans.push_back(root->data);
    if(root->left) leftb(root->left);
    else leftb(root->right);
}

void leaves(TreeNode<int> *root){
    if(root==NULL) return;
    if(root->left==NULL and root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    if(root->left) leaves(root->left);
    if(root->right) leaves(root->right);
}

void rightb(TreeNode<int> *root){
    if(root==NULL) return;
    if(root->left==NULL and root->right==NULL) return;
    if(root->right) rightb(root->right);
    else rightb(root->left);
    ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    ans.clear();
    if(root==NULL) return ans;
    if(root->left==NULL and root->right==NULL) return {root->data};
    ans.push_back(root->data);
    leftb(root->left);
    leaves(root);
    rightb(root->right);
    return ans;
}
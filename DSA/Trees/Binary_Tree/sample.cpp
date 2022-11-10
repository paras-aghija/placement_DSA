// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int position(int in[], int e,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(in[i]==e)
                return i;
        }
        return -1;
    }
    Node* solve(int in[],int pre[], int &pr,int inorder,int ie, int n)
    {
        if(pr>=n|| inorder>ie)
            return NULL;
        int e=pre[pr++];
        Node* root=new Node(e);
        int pos=position(in,e,n);
        root->left=solve(in,pre,pr,inorder,pos-1,n);
        root->right=solve(in,pre,pr,pos-1,ie,n);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int pr=0;
        Node *ans;
        ans=solve(in,pre,pr,0,n-1,n);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends
#include<bits/stdc++.h>
using namespace std;

/*
BALANCED BINARY TREE
Difference between heights of left subtree and right subtree is atmost 1.

TO FIND IF THE GIVEN BINARY TREE IS BALANCED OR NOT

*/

struct Node
{
	int data;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

bool isBalanced(Node *root, int *height)
{
	cout<<root->data<<endl;
	if(root == NULL)
	{
		*height = 0;
		return true; 
	}
	int *lheight = 0, *rheight = 0;
	bool lbalanced = isBalanced(root->left, lheight);
	bool rbalanced = isBalanced(root->right, rheight);

	if(abs(*lheight - *rheight)>1)
		return false;

	*height = max(*lheight, *rheight) + 1;

	return(lbalanced && rbalanced);


}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif

	Node *root = new Node(10);
	root->left = new Node(3);
	root->right = new Node(7);
	root->right->left = new Node(5);
	root->right->right = new Node(2);
	int *t = 0;

	cout<<isBalanced(root,t)<<endl;
	// root->left->left = new Node(6);
	// cout<<isBalanced<<endl;

	return 0;
}
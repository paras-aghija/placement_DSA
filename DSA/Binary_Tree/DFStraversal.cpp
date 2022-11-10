#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;

	Node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};


void postorder(Node *t)
{
	if(t==NULL)
		return;

	postorder(t->left);
	postorder(t->right);
	cout<<t->data<<" ";
}

void preorder(Node *t)
{
	if(t==NULL)
		return;

	cout<<t->data<<" ";
	preorder(t->left);
	preorder(t->right);
}

void inorder(Node *t)
{
	if(t==NULL)
		return;

	inorder(t->left);
	cout<<t->data<<" ";
	inorder(t->right);
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

	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout<<"\nInorder : ";
	inorder(root);
	cout<<"\nPreorder : ";
	preorder(root);
	cout<<"\nPostorder : ";
	postorder(root);

	return 0;
}
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *right;
	Node *left;

	Node(int x)
	{
		data = x;
		right = NULL;
		left = NULL;
	}
};

Node* newnode(int x)
{
	Node *n = new Node(x);
	return n;
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

	Node *root = newnode(1);	
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);

	cout<<root->left->right->data;


	return 0;
}
#include<bits/stdc++.h>
using namespace std;


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

int height(Node *root)
{
	if(root == NULL)
		return -1;

	if(root->left == NULL && root->right == NULL)
		return 0;

	int lh = height(root->left);
	int rh = height(root->right);

	return (max(lh,rh) + 1);
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
	root->left = new Node(5);
	root->right = new Node(20);
	root->left->left = new Node(3);
	root->left->right = new Node(5);
	root->left->left->right = new Node(15);
	root->left->left->right->left = new Node(9);
	root->right->right = new Node(6);

	cout<<"Height of BT : "<<height(root)<<endl;

	Node *root2 = NULL;
	cout<<height(root2)<<endl;
	root2 = new Node(2);
	cout<<height(root2);


	return 0;
}
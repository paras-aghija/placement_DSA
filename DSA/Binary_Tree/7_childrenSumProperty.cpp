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
bool childrenSum(Node *root)
{
	if(root == NULL)
		return true;

	if(root->left == NULL && root->right == NULL) // condition for leaf node
		return true;

	int sum = 0;

	if(root->left != NULL)
		sum += root->left->data;

	if(root->right != NULL)
		sum += root->right->data;

	if(sum == root->data && childrenSum(root->left) && childrenSum(root->right))
		return true;

	else
		return false;
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

	cout<<childrenSum(root)<<endl;
	root->left->left = new Node(6);
	cout<<childrenSum(root);


	/*
	CHILDREN SUM PROPERTY IS 
	Node value must be equal to sum of left child and right child
	If a node contains single child then we consider empty side as 0
	single node also follows the children sum property
	*/
	return 0;
}
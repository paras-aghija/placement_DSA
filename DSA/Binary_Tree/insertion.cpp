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

void inorder(Node *temp)
{
	if(temp == NULL)
		return ;

	inorder(temp->left);
	cout<<temp->data<<" ";
	inorder(temp->right);
}

void insert(Node *temp, int x)
{
	queue<Node*> q;
	q.push(temp);

	//Level order traversal of 
	//tree unitll we find and empty space

	while(!q.empty())
	{
		Node *t=q.front();
		q.pop();

		if(!t->left) //If left of t is Null
		{
			t->left = new Node(x);
			break;
		}
		else
			q.push(t->left);

		if(!t->right) //If left of t is Null
		{
			t->right = new Node(x);
			break;
		}
		else
			q.push(t->right);
	}
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
	root->left = new Node(11);
	root->left->left = new Node(7);
	root->right = new Node(9);
	root->right->left = new Node(15);
	root->right->right = new Node(8);
	
	cout<<"\nInorder before insertion : ";
	inorder(root);

	int x = 12;
	insert(root, 12);
	cout<<"\nInorder after insertion : ";
	inorder(root);

	return 0;
}
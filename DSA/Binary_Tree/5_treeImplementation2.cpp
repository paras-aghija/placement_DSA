#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *right, *left;
	Node(int x)
	{
		data = x;
		right = left = NULL;
	}
};

Node *root;//global root

void create()
{
	int x;
	queue<Node *> q;
	cout<<"Enter root value : ";
	cin>>x;

	root = new Node(x);
	q.push(root);
	while(!q.empty())
	{
		Node *temp = q.front();
		q.pop();

		cout<<"Enter left child for "<<temp->data<<" : ";
		cin>>x;

		if(x!=-1)
		{
			Node *t = new Node(x);
			temp->left = t;
			q.push(t);
		}


		cout<<"Enter right child for "<<temp->data<<" : ";
		cin>>x;

		if(x!=-1)
		{
			Node *t = new Node(x);
			temp->left = t;
			q.push(t);
		}

	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	create();


	return 0;
}
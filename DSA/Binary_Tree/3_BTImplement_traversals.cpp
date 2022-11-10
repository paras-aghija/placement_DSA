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

/*
it is better to make a separate binary tree class and declate its own functions
but in cp we generally use trees only from Node structure as it can
be efficiently passed into recursive functions

We can traverse a binary tree in different no. of ways

	1- Depth First Traversal

		-Inorder Traversal : [ left->root->right ]
		-Preorder Traversal : [ root->left->right ]
		-Postorder Traversal : [ left->rigth->root ]

	2- Breadth First Traversal ( Level Order Traversal )
		Simple print each level in order from left to right

*/
//DEPTH FIRST TREE TRAVERSALS

void inOrder(Node *root)
{
	if(root == NULL)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void preOrder(Node *root)
{
	if(root == NULL)
		return;
	
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(Node *root)
{
	if(root == NULL)
		return;
	
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

void levelOrder(Node *root)
{
	queue<Node *> q;
	q.push(root);
	while(!q.empty())
	{
		Node *curr = q.front();
		q.pop();
		cout<<curr->data<<" ";
		if(curr->left != NULL)
			q.push(curr->left);
		if(curr->right != NULL)
			q.push(curr->right);
	}
	//when last item of a level is poped from the queue then
	//next corresponding level is completely inserted inside the queue
	//extra space being used is maximum width of the binary tree
	//in dfs space used is comparitively less
	//if tree is skwed then dfs also takes larger space
	//space in dfs is being used by the stack storing recursive calls
}

//TC of all traversals is O(n)

//NOTE : In linked representation of binary tree
//if tree has n nodes in total then there will be n+1 null pointers

//ITERATIVE TRAVERSALS

void iterativeInorder(Node *root)
{

	if(root == NULL)
		return;

	Node *temp = root;
	stack<Node *> s;

	while(temp!=NULL || !s.empty())
	{

		while(temp!=NULL)
		{
			s.push(temp);
			temp = temp->left;
		}

		// temp is null now
		temp = s.top();
		s.pop();

		cout<<temp->data<<" ";

		temp = temp->right;

	}
}

void iterativePreorder(Node *root)
{

	if(root == NULL)
		return;

	Node *temp = root;
	stack<Node *> s;
	s.push(temp);

	while(!s.empty())
	{
		Node *t = s.top();
		cout<<t->data<<" ";
		s.pop();

		if(t->right)
			s.push(t->right);

		if(t->left)
			s.push(t->left);
	}
}

// void iterativePostorder(Node *root)
// {
// 	Node *temp = root;
// 	stack<Node *> s;
// 	s.push(temp);

// 	while(!s.empty())
// 	{
		
// 	}

// }

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
	root->right->left = new Node(15);
	root->right->right = new Node(6);
	// // //and so on we can connect further nodes

	// // //inorder   : 3 5 5 10 15 20 6 
	// // //preorder  : 10 5 3 5 20 15 6
	// // //postorder : 3 5 5 15 6 20 10 
	// // //levelorder: 10 5 20 3 5 15 6

	inOrder(root);
	cout<<endl;
	preOrder(root);
	cout<<endl;
	postOrder(root);
	cout<<endl;
	levelOrder(root);
	cout<<endl<<endl;
	iterativeInorder(root);
	cout<<endl;
	iterativePreorder(root);

	return 0;
}
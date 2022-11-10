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

// delete given deepest node
void deletedeepest(Node *root, Node *x)
{
	queue<Node*> q;
	q.push(root);

	Node *temp;
	while(!q.empty())
	{

		temp = q.front();
		q.pop();
		   
		if(temp==x)
		{
			temp=NULL;
			delete(x);
			return;
		}

		if(temp->right)
		{

			if(temp->right==x)
			{
				temp->right=NULL;
				delete(x);
				return;
			}
			else
				q.push(temp->right);
		}

		if(temp->left)
		{
			if(temp->left==x)
			{
				temp->left=NULL;
				delete(x);
				return;
			}
			else
				q.push(temp->left);
		}

	}
}

Node* deletion(Node* root, int key) 
{ 
    if (root == NULL) 
        return NULL; 
  
    if (root->left == NULL && root->right == NULL) { 
        if (root->data == key) 
            return NULL; 
        else
            return root; 
    } 
  
    queue<Node*> q; 
    q.push(root); 
  
    Node* temp; 
    Node* key_node = NULL; 
  
    // Do level order traversal to find deepest 
    // node(temp) and node to be deleted (key_node) 
    while (!q.empty()) { 
        temp = q.front(); 
        q.pop(); 
  
        if (temp->data == key) 
            key_node = temp; 
  
        if (temp->left) 
            q.push(temp->left); 
  
        if (temp->right) 
            q.push(temp->right); 
    } 
  
    if (key_node != NULL) { 
        int x = temp->data; 
        deletedeepest(root, temp); 
        key_node->data = x; 
    } 
    return root; 
}
//if node to be deleted is a internal node
//then we cannot directly delete
//as child nodes will also get deleted

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif

	Node* root = new Node(10); 
    root->left = new Node(11); 
    root->left->left = new Node(7); 
    root->left->right = new Node(12); 
    root->right = new Node(9); 
    root->right->left = new Node(15); 
    root->right->right = new Node(8);

    cout << "Inorder traversal before deletion : "; 
    inorder(root); 
  
    int key = 11; 
    root = deletion(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after deletion : "; 
    inorder(root); 

	return 0;
}
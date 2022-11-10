#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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

// DFS Traversals => inorder preorder postorder

// preorer => root left right
// inorder => left root right
// postorder => left right root

// recursive

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

// iterative

void ipreorder(Node *root){
	stack<Node *> s;
	s.push(root);
	while(!s.empty()){
		Node *x = s.top();
		s.pop();
		cout<<x->data<<" ";
		if(x->right) s.push(x->right);
		if(x->left) s.push(x->left);
	}
}

void iinorder(Node *root){
	stack<Node *> s;
	Node *temp = root;
	while(1){
		if(temp!=NULL){
			s.push(temp);
			temp=temp->left;
		}
		else{
			if(s.empty()) break;
			temp = s.top();
			s.pop();
			cout<<temp->data<<" ";
			temp=temp->right;
		}
	}
}

void ipostorder(Node *root){
	stack<Node*> s1, s2;
	s1.push(root);
	while(!s1.empty()){
		Node *x = s1.top();
		s1.pop();
		s2.push(x);
		if(x->left) s1.push(x->left);
		if(x->right) s1.push(x->right);
	}

	string ans = "";
	while(!s2.empty()){
		ans += to_string(s2.top()->data) + " ";
		s2.pop();
	}
	cout<<ans;
}

void ipostorder_1stack(Node *root){
	stack<Node *> s;
	Node *temp = root, *t;
	while(temp!=NULL or !s.empty()){
		if(temp!=NULL){
			s.push(temp);
			temp = temp->left;
		}
		else{
			t = s.top()->right;
			if(t==NULL){
				t = s.top();
				s.pop();
				cout<<t->data<<" ";
				while(!s.empty() and t==s.top()->right){
					t = s.top();
					cout<<t->data<<" ";
					s.pop();
				}
			} else{
				temp=t;
			}
		}
	}
}

// BFS / Level Order Traversal

void bfs(Node *root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node *x = q.front();
		q.pop();
		cout<<x->data<<" ";
		if(x->left) q.push(x->left);
		if(x->right) q.push(x->right);
	}
}

// Preorder Inorder Postorder in a single pass

void printv(vector<int> v){
	for(int x : v) cout<<x<<" ";
	cout<<endl;
}

void allorder(Node *root){

	vector<int> preorder, inorder, postorder;
	stack<pair<Node*, int>> s;
	s.push({root, 1});
	while(!s.empty()){
		auto x = s.top();
		s.pop();
		if(x.second==1){
			preorder.push_back(x.first->data);
			s.push({x.first, 2});
			if(x.first->left) s.push({x.first->left, 1});
		} else if(x.second==2){
			inorder.push_back(x.first->data);
			s.push({x.first, 3});
			if(x.first->right) s.push({x.first->right, 1});
		} else {
			postorder.push_back(x.first->data);
		}
	}

	printv(preorder);
	printv(inorder);
	printv(postorder);

}

// Morris Traversal 
// Recursive => TC: O(n) SC: O(n)
// Iterative => TC: O(n) SC: O(n)
// Morris 	 => TC: O(n) Sc: O(1)
// Morris Traversal uses threaded binary tree
// Inorder : Left Root Right
// Preorder: Root Left Right
 


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout<<"Recursive DFS :- ";
	cout<<"\nPreorder : ";
	preorder(root);
	cout<<"\nInorder : ";
	inorder(root);
	cout<<"\nPostorder : ";
	postorder(root);

	cout<<"\n\nIterative DFS :- ";
	cout<<"\nPreorder: ";
	ipreorder(root);
	cout<<"\nInorder: ";
	iinorder(root);
	cout<<"\nPostorder (2Stack): ";
	ipostorder(root);
	cout<<"\nPostorder (1Stack): ";
	ipostorder_1stack(root);

	cout<<"\n\nLevel Order: ";
	bfs(root);

	cout<<"\n\nAll Orders :-\n";
	allorder(root);

	return 0;
}
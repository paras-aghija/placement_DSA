#include<bits/stdc++.h>
using namespace std;

/*
Vertical Order Print
Distance to the left of root is negetive
distance to the right of root is positive

for the given tree vertical order print

-2	4
-1	2
0	1 5 6
1	3 8
2	7
3	9

*/

struct Node
{
	int data;
	Node *left;
	Node *right;

	Node(int key)
	{
		data = key;
		left = NULL;
		right = NULL;
	}
};

void verticalOrderPrint(Node *root,int d, map<int,vector<int>> &m)
{
	//pass al stl containers by reference to avoid making copy separately
	if(root == NULL)
		return;

	//otherwise
	m[d].push_back(root->data);
	verticalOrderPrint(root->left,d-1,m);
	verticalOrderPrint(root->right,d+1,m);
	return;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	root->right->left = new Node(6);
	root->right->right = new Node(7);

	root->right->right->right = new Node(9);
	root->left->right->right = new Node(8);

	map<int,vector<int>> m;
	int d = 0;
	verticalOrderPrint(root,d,m);

	for(auto p : m)
	{
		cout<<p.first<<"\t";
		for(auto s : p.second)
			cout<<s<<" ";

		cout<<endl;
	}
	return 0;

}
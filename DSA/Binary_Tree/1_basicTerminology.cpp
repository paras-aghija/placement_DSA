#include<bits/stdc++.h>
using namespace std;

/*
BASIC TREE TERMINOLOGY

Tree is a non linear data structure, it is a heirarichal data structure
Each node in a tree might represents a parent or a child node
if there are n nodes in a tree than there are n-1 edges in a tree
Root node is the starting point of the tree from where the branching begins
children of root node can further be considered as a sub tree
No cyclic loop is present inside a tree as then it will become a graph data structure

	1.Root : the first node of the tree is the root node
			root node do not hav any parent

	2.Parent : A node is a pernet to its very next descendents

	3.Child : the very next descendent of the parent node is its child node

	4.Siblings : if A have two child nodes B and C then B and C 
			are siblings (children of same parent)

	5.Descendents : All nodes below a given node A which can be 
			reached throuch A are descendents of A

	6. Ancestors : for a given node its parent, grand parent.
			grand grand parent....are its ancestors

	7.Degree : No. of direct children a node is having
			Degree of leaf node is 0

	8.Internal/External nodes : Leaf nodes -> external nodes -> terminal nodes
			nodes which do not have degree 0 are non terminal nodes -> internal nodes

	9.Levels : Level starts from 1. Root is at level one its children are at level 2
			grand children of roots are at level 3 and so on

	10.Height : no. of edges from the node to the root gives height of that node 

	11.Forest : A collection of trees is a forest
			If we remove root node then remaing subtrees collection is a forest

BINARY TREE

A tree having degree 2, i.e. it can have maximum 2 children only.
a node consists atmost 2 child, left child and right child

* A tree in which all nodes have only left child is called a Left Skewed Binary Tree
* And one in which each node only have right child is called Right Skewed Binary Tree


APPLICATIONS OF TREES

	- Folder Structure
	- Company Organnisation Structure
	- Family Tree
	- XML and HTML data storage (working of tags)
	  HTML tag which is root of all the tags
	  It has head and body as its children and so it goes on internally


HEIGHT VS NODES

CASE 1 : For given height

	for h = 1

	min nodes for condition = 2 
	max nodes possible = 3

	for h = 2

	min nodes = 3
	max nodes = 7

	h = 3

	min nodes = 4
	max nodes = 15

	General formula

	min nodes = (h + 1)
	max nodes = [2^(h + 1) - 1]

CASE 2 : For given nodes

	for n = 3

	min height = 1
	max height = 2

	for n = 7

	min height = 2
	max height = 6

	for n = 15

	min height = 3
	max height = 14

	General formula

	min height = floor[ log2( n + 1 ) - 1 ]  derived from max nodes formula
	max height = n - 1

NOTE : nodes with deg(0) = [ nodes with deg(2) + 1 ] ALWAYS TRUE

STRICT BINARY TREES

	In a Strict binary tree a node can have 0 or 2 children, 1 child not allowed

	HEIGHT VS NODES IN STRICT BINARY TREES

	h = 2

	min nodes = 5
	max nodes = 7

	h = 3

	min nodes = 7
	max nodes = 15

	General Formula if height is given

	min nodes = 2h + 1
	max nodes = 2^(h + 1) - 1

	General formula if nodes are given

	min height = log2( n + 1 ) - 1
	max height = (n - 1)/2

NOTE : In a strict binary trees[ e = i + 1 ]
	No. of external nodes = No. of internal nodes + 1

ANALYSIS OF STRICT N-ary TREE

	for a given height h

	min nodes = N*h + 1
	max nodes = [N^(h+1)-1]/N-1

	for a given no. of nodes

	min height = logn[ {n * (N-1)} + 1] - 1
	max height = (n - 1)/N

	NOTE : for a strict N-ary tree

		e = (N-1)i + 1

FULL BINARY TREE/ COMPLETE BINARY TREE/ 

	Full Binary Tree : A binary tree of height h having maximum no. o nodes
	Complete Binary Tree : If a binary tree is represented in an array
	then there should be no blank spaces present in between the elements
	it is called a complete binary tree

	A complete binary tree will be a full binary tree upto height h-1
	

*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif
	return 0;
}
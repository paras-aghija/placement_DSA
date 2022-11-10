#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

/*

Full BT : 0 or 2 children
Complete BT : All levels filled except the last level (last level has all nodes towards left)
Perfect BT : All leaf nodes are at same level
Balanced BT : Height log(n)
Degenerate BT / Skew Tree : Linkedlist type every node has single children


*/

struct node{

	int val;
	node *left;
	node *right;

	node(int x){
		val = x;
		left = right = NULL;
	}

};

int main(){
	
		FIO;
		cout<<"Hellow";	

	return 0;
}
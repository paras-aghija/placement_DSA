#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void printKth(Node *root, int k){
	if(root==NULL) return ;
	if(k==0){
		cout<<root->val<<" ";
		return;	
	} 
	if(root->left) printKth(root->left, k-1);
	if(root->right) printkth(root->right, k-1);
}

int main(){
	
	FIO;
	

	return 0;
}
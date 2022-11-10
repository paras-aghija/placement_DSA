#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void bubbleSort(vector<int> &a, int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]) swap(a[j], a[j+1]);
		}
	}
}

void printv(vector<int> v){
	for(int x : v) cout<<x<<" ";
	cout<<endl;
}

int main(){
	
	FIO;
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &x : v) cin>>x;
	bubbleSort(v,n);
	printv(v);

	return 0;
}
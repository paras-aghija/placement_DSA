#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void selectionSort(vector<int> &v, int n){
	for(int i=0;i<n-1;i++){
		int mini = i;
		for(int j=i+1;j<n;j++){
			if(v[j]<v[mini]) mini = j;
		}
		swap(v[i], v[mini]);
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
	selectionSort(v,n);
	printv(v);

	return 0;
}
#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void printv(vector<int> v){
	for(int x : v) cout<<x<<" ";
	cout<<endl;
}

int partition(vector<int> &v, int l, int r){
	int i = l-1;
	int pivot = v[r];

	for(int j=l;j<r;j++){
		if(v[j]<pivot){
			i++;
			swap(v[i], v[j]);
		}
	}
	swap(v[i+1], v[r]);
	return i+1;
}

void quickSort(vector<int> &v, int l, int r){
	if(l<r){
		int p = partition(v, l, r);
		quickSort(v, l, p-1);
		quickSort(v, p+1, r);
	}
}



int main(){
	
	FIO;
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &x : v) cin>>x;
	quickSort(v,0, n-1);
	printv(v);

	return 0;
}
#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void printv(vector<int> v){
	for(int x : v) cout<<x<<" ";
	cout<<endl;
}

void merge(vector<int> &v, int l, int m, int r){
	int x = m-l+1, y = r-m;
	vector<int> a(x), b(y);
	for(int i=0;i<x;i++) a[i] = v[l+i];
	for(int j=0;j<y;j++) b[j] = v[m+j+1];

	int i=0, j=0, k=l;
	while(i<x and j<y){
		if(a[i]<b[j]) v[k++] = a[i++];
		else v[k++] = b[j++];
	}
	while(i<x) v[k++] = a[i++];
	while(j<y) v[k++] = b[j++];
}

void mergeSort(vector<int> &v, int l, int r){
	if(l<r){
		int mid = l + (r-l)/2;
		mergeSort(v, l, mid);
		mergeSort(v, mid+1, r);
		merge(v, l, mid, r);
	}
}



int main(){
	
	FIO;
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &x : v) cin>>x;
	mergeSort(v,0 ,n-1);
	printv(v);

	return 0;
}
#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void insertionSort(vector<int> &v, int n){
	for(int i=1;i<n;i++){
		int x = v[i];
		int j=i-1;
		while(j>=0 and v[j]>x){
			v[j+1] = v[j];
			j--;
		}
		v[j+1]=x;
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
	insertionSort(v,n);
	printv(v);

	return 0;
}
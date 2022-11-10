#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

// search space [1.....m]
// 

double multiply(double num, int n){
	double ans = 1;
	for(int i=0;i<n;i++) ans*=num;
	return ans;
}

double findNthRootOfM(int n, long long m) {
	// Write your code here.
	double l=1, h=m;
	double br = 1e-6;
	while(h-l > br){
		double mid = l + (h-l)/2.0;
		if(multiply(mid, n)<m){
			low=mid;
		} else{
			high=mid;
		}
	}
	return l;
}


int main(){
	
	FIO;
	

	return 0;
}
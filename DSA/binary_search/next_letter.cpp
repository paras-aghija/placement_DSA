#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int solve(string v, char c){
	int s=0, e=v.length()-1;
	int res=v.length();
	while(s<=e){
		int mid = s+(e-s)/2;
		if(v[mid]==c) return mid;
		else if(v[mid]<c) s=mid+1;
		else{
			res = mid;
			e = mid-1;
		}
	}
	return res;
}

int main(){
	
	FIO;
	string s;
	cin>>s;

	char c;
	cin>>c;
	cout<<solve(s,c);

	return 0;
}

// string version of ceil problem

#include<bits/stdc++.h>
using namespace std;

/*
PREFIX SUM
Given an array and we want to perform multiple queries on the array
Prefix sum is a precomputation of n array which helps in solving the queries on O(1) time

Problem statement to find the sum of element of subarrays
where starting and ending index is provided in the queries

arr[] = {2,8,3,9,6,,5,4}
prefixSum[] = {2,10,13,22,28,33,37} 

*/

void rangeSum(int a[], int n)
{
	int prefixSum[n] = {a[0]};
	for(int i=1;i<n;i++)
		prefixSum[i] = prefixSum[i-1] + a[i];

	int t,s,e,sum;
	cin>>t;
	while(t--)
	{
		cin>>s>>e;

		if(s==0)
			sum = prefixSum[e];

		else
			sum = prefixSum[e] - prefixSum[s-1];

		cout<<"Sum "<<s<<"->"<<e<<" : "<<sum<<endl;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	rangeSum(a,n);
	return 0;
}
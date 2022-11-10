#include<bits/stdc++.h>
using namespace std;

/*
Problem Statement
Check is the given array have any subarray where sum of elements in subaaray = 0

Brute force :-

	generate all sybarrays and find maximum sum
	Time Complexity : O(n^2)

Hash Table Approach :-

	-we create an empty hash table
	-we transform the given array to a prefix sum array
	-we traverse through the prefix sum array
	-if element not present in hash table then add
	-else if already present then return 0 subarray found
	-
*/

//my try
void zeroSumSubarray(int *a, int n)
{
	int f = 0;
	int b[n];
	for(int i=0;i<n;i++)
		b[i] = a[i];

	int start = n,end = n;
	for(int i=1;i<n;i++)
		b[i] += b[i-1];

	unordered_map<int,int> m;
	for(int i=0;i<n;i++)
	{
		if(m.count(b[i]) == 1)
		{
			f = 1;
			start = m[b[i]];
			end = i;
			for(int j=start+1;j<=end;j++)
				cout<<a[j]<<" ";

			cout<<endl;
		}

		if(b[i] == 0)
		{
			f = 1;
			for(int j=0;j<=i;j++)
				cout<<a[j]<<" "; 

			cout<<endl;
		}

		else
			m[b[i]] = i;
	}

	if(f == 0)
		cout<<"No zero sum subarray present";

	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	zeroSumSubarray(a,n);

	return 0;
}
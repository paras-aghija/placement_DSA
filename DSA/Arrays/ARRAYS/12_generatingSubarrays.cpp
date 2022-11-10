#include<bits/stdc++.h>
using namespace std;

/*
arr[] = 1,2,3,4

Possible Subarrays :-

length 1 : 1	2	3	4
length 2 : 12	23	34	(24 is not a subarray)
length 3 : 123	234
length 4 : 1234

*/

void subarray1(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			//this will give all pairs of i,j where j>=i
			//this loop prints elements starting from i and ending at j
			for(int k = i; k<=j; k++)
				cout<<a[k]<<" ";

			cout<<endl;
		}
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
	
	subarray1(a,n);
	return 0;
}
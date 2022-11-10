#include<bits/stdc++.h>
using namespace std;

/*
Problem Statement
To find the longest subarray with sum of elements in it 0

We will just modify our previous code
*/

void longestZeroSumSubarray(int *a, int n)
{
	int f = 0;

	//making separate array having elements of a
	int b[n];
	for(int i=0;i<n;i++)
		b[i] = a[i];

	int start = n,end = n;

	//prefix sum calculation
	for(int i=1;i<n;i++)
		b[i] += b[i-1];

	int maxlen = 0;

	unordered_map<int,int> m;
	for(int i=0;i<n;i++)
	{
		if(m.count(b[i]) == 1)
		{
			f = 1;
			start = m[b[i]];
			end = i;
			if((end - start) > maxlen)
				maxlen = end - start;
		}

		if(b[i] == 0)
		{
			f = 1;
			if(i > maxlen)
				maxlen = i+1;
		}

		else
			m[b[i]] = i;
	}

	if(f == 0)
		cout<<"No zero sum subarray present"<<endl;

	else
		cout<<"Max length of zero sum subarray is "<<maxlen<<endl;

	
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
	
	longestZeroSumSubarray(a,n);
	return 0;
}
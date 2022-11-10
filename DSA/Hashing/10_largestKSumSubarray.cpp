#include<bits/stdc++.h>
using namespace std;

/*
a[] = 1 -1 5 -2 3
k = 3

prefix sum array : 1 0 5 3 6
possible subarrays with sum k

pi = sum(0,i)
pj = sum(0,j)

pj - pi = k
or curr element in prefix sum is k
then elements from start to curr make a suarray with sum k

pi = pj - k
use map and this formula to compute the algorithm 

*/

int longestSubarrayWithSumK(int a[], int n, int k)
{
	unordered_map<int, int> mp;
	int pre = 0;
	int len = 0;
	for(int i=0;i<n;i++)
	{
		pre+=a[i];
		if(pre == k)
			len = max(len,i+1);

		if(mp.find(pre-k) != mp.end())
			len = max(len,i - mp[pre-k]);

		else
			mp[pre] = i;

	}
	return len;
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

	int k;
	cin>>k;
	
	int b = longestSubarrayWithSumK(a,n,k);
	cout<<b<<endl;
	return 0;
}
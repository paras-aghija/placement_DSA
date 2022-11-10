#include<bits/stdc++.h>
using namespace std;

/*
SLIDING WINDOW TECHNIQUE
A sliding window is a sublist tht runs over a large array
arr[] = 1,2,3,4,5,6,7
If we run a window of size k = 4 over the array
Possible window combinations we we get are

1,2,3,4
2,3,4,5
3,4,5,6
4,5,6,7

on each slide only two elements change 
the strting element of the window and the ending element

*/

/*
PROBLEM : Max sum of k consecutive elements
SLIDING WINDOW METHOD
arr[] = {1,2,3,1,4,5}
k = 3

1,2,3 -> 6
2,3,1 -> 6
3,1,4 -> 8
1,4,5 -> 10

output -> 10
*/

int maxkSum(int a[], int n, int k)
{
	int window_sum = 0;
	for(int i=0;i<k;i++	)
		window_sum += a[i];

	int max = window_sum;
	for(int i=k;i<n;i++)
	{
		window_sum = window_sum + a[i] - a[i-k];
		if(window_sum > max) 
			max = window_sum; 
	}	
	return max;
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

	int k;
	cin>>k;

	cout<<maxkSum(a,n,k);
	

	return 0;
}
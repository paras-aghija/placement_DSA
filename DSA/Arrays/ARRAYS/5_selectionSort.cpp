#include<bits/stdc++.h>
using namespace std;

/*
SELECTTION SORT

Start from 0th index and find the min element in the proceding array
swap the element at 0 index with the minimum element
now 1st element of the sorted array has reached its proper location
rpeat the same for rest elements
start from the 1st index and search for minimum in the proceding array
again swap and so the process goes on

*/

void seletionSort(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		int min = a[i];
		int pos = i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<min)
			{
				min = a[j];
				pos = j;
			}
		}
		swap(a[i],a[pos]);
		//inbuilt swap function in c++
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

	seletionSort(a,n);

	for (int i = 0; i < n; ++i)
		cout<<a[i]<<" ";
	
	return 0;
}
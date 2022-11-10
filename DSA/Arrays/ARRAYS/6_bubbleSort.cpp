#include<bits/stdc++.h>
using namespace std;

/*

BUBBLE SORT

push larger elements to end of the array

54321
45321
43521
43251
43215

after 1 pass largest element moves to the end
now sorting for a of size n-1 is left

43215
34215
32415
32145

pass 2 completed

32145
23145
21345

pass 3 completed

21345
12345

pass 4 completed

max passes needed = size - 1

first loop for the number of passes
inner loop to compare starting from 0 to n-pass-1
as for a given pass some elements might have got
to their sorted position in the last

compare a[j]>a[j+1] -> swap to move bigger to right

*/

void bubbleSort(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
		}
	}
}

void recursiveBubbleSort(int a[], int n)
{
	if(n==1)
		return;

	for(int i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
			swap(a[i],a[i+1]);
	}
	recursiveBubbleSort(a,n-1);
	//pass loop is handled by recursion
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
	
	bubbleSort(a,n);
	for (int i = 0; i < n; ++i)
		cout<<a[i]<<" ";


	return 0;
}
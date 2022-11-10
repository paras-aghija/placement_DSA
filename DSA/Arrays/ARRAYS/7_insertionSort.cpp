//SORTING
//INSERTION SORT
#include<bits/stdc++.h>
using namespace std;

/*
INSERTION SORT

basically we will have two sections in an array
1st section is sorted and proceding section is unsorted
we have to take starting element of the unsorted part 
and insert it in the sorted part at the right location


in insertion sort we compare backwards
start from index i = 1 and compare backwards
for each pass move i++ and again compare backwars
basically new element in the inserted array needs to
get to its sorted position
initially considering a subarray of size 1 as sorted
i.e. 5 new elemet inserted is 2

i=1
52301
25301

i=2
25301
23501

i=3
23501
23051
20351
02351

i=4
02351
02315
02135
01235

for i = a
all elements before ath index are sorted already


*/

void insertionSort(int a[], int n)
{
	for(int i=1;i<n;i++)
	{
		int e = a[i];
		int j=i-1;
		while(a[j]>e && j>=0)
		{	
			a[j+1] = a[j];//shifting the elements bigger than e to right
			j--;
		}	
		a[j+1] = e;	
	}
}

void recursiveInsertionSort(int a[],int n)
{
	//base case
	if(n <= 1)
		return;

	recursiveInsertionSort(a,n-1);
	
	int last = a[n-1];
	int j=n-2;
	while(a[j]>e && j>=0)
		{	
			a[j+1] = a[j];//shifting the elements bigger than e to right
			j--;
		}	
		a[j+1] = last;
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

	insertionSort(a,n);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}
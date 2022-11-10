#include<bits/stdc++.h>
using namespace std;

/*
QUICK SORT ALGORITHM

Avg case time complexity : O(nlogn)
Worst Case : O(n^2)
Inplace algorithm without using extra space

2,7,8,6,1,5,4
chose one element of the array as pivot element
let it be 4
Divide the array in two parts
1 part will have the elements which are <= pivot
another part will have elements which are > pivot

A1		A2
2,1, 4 ,7,8,6,5
now 4 reaches its proper position
recursively sort the two parts A1 and A2

A1 2,1 -> 1 as pivot element -> 1 ,2
									   A3
A2 7,8,6,5 -> 5 as pivot element -> 5 ,7,8,6

A3 7,8,6 -> 6 as pivot element -> 6 ,7,8 (Sorted)

Finally array will be sorted


*/

int partition(int *a, int s, int e)
{
	//implace cant take extra space
	int i = s-1;//ending point of smaller elements
	int j = s;//ending point of larger elements
	int pivot = a[e];
	//we need to maintain 2 regions 
	//one containing mall elements and one containing bigger element than pivot element

	for( ; j < e;)
	{
		if(a[j] <= pivot)
		{
			i++;
			//we have to merger smaller element in region 1
			swap(a[i],a[j]);
			// element at jth position which must be in region 1 is swapped with the starting
			//element of the region 2 and i is incremented to mark expasion of region 1 
		}

		j++;
		//just moves forward if the current element lies in region 2
		//as region 1 and 2 will automatically be made due to separation happening with above code
	}
	//place thi pivot element in the correct position
	swap(a[i+1],a[e]);

	return i+1;
	//return the position of the pivot element
	//index is needed to recursively sort the oter two parts

}

void quickSort(int *arr, int s, int e)
{
	//base case
	if(s>=e)
		return;

	//recursive case
	int p = partition(arr,s,e);
	//helper method to locate the pivot elemeent

	//recursively quicksort left part
	quickSort(arr,s,p-1);
	//recursively sort the righ part
	quickSort(arr,p+1,e);
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
	
	quickSort(a,0,n-1);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

/*
BINARY SEARCH
Efficient way to search for an element in a sorted array

9 elements
a[] = 1,2,3,5,7,10,11,12,15
key = 3

Int binary search we first find the mid element
mid = (start + end) / 2

a[mid] = 7 
since we knw that the array is sorted therefore elements after 7 are of no use
therefore we discard elements after 7 and only consider elements before 7

1,2,3,5,7

mid = 3
a[mid] = 3

element found return index

It is more efficient as whole array is not traversed in binary search
Time Complexity = O(logn)
Each time if element is not found array reduces to half its size


*/

int binarySearch(int a[], int n, int key)
{
	sort(a,a+n);
	//inbuilt function to sort the given array
	int low = 0, high = n-1, mid;
	while(low <= high)
	{
		mid = (low + high)/2;
		if(a[mid] == key)
			return mid;

		else if(a[mid] > key)
			high = mid - 1;

		else if(a[mid] < key)
			low = mid + 1;
	}
	return -1;
}

int rbinarySearch(int a[], int s, int e, int key)
{
	if(s==e)
	{
		if(a[s]==key)
			return s;

		else return -1;
	}

	int mid = (s+e)/2;

	if(a[mid] == key)
		return mid;

	else if(a[mid]>key)
		rbinarySearch(a,0,mid,key);

	else if(a[mid]<key)
		rbinarySearch(a,mid+1,e,key);
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
	
	cout<<"Index : "<<rbinarySearch(a,0,n,2);
	return 0;
}
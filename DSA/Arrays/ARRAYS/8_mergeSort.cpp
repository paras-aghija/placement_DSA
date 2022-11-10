//SORTING
//MERGESORT
//DIVIDE AND CONQUER
#include<bits/stdc++.h>
using namespace std;

/*

561240

561	240 	divide

i=0	j=0
156 024 	sort recursively

012456		merge using two pointer approach

compare 1 and 0
push 0
compare 1 and 2
push 1
compare 5 and 2
push 2
compare 5 and 4
push 4

push remaining array

*/


void merge(int *a,int s, int e)
{
	int mid = (s+e)/2;

	int i=s,j=mid+1,k=s;
	int temp[100];

	while(i<=mid && j<=e)
	{
		if(a[i]<a[j])
			temp[k++] = a[i++];

		else
			temp[k++] = a[j++];
	}
	while(i<=mid)
		temp[k++] = a[i++];

	while(j<=e)
		temp[k++] = a[j++]; 

	//copying back elements to a passed as a pointer
	for(int i=s;i<=e;i++)
		a[i] = temp[i];
}

void mergeSort(int a[],int s, int e)
{
	if(s>=e)//single element
		return;

	//divide
	int mid = (s+e)/2;

	//recursively sort two arrays
	mergeSort(a,s,mid);
	mergeSort(a,mid+1,e);

	// merge the two parts
	merge(a,s,e);


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

	mergeSort(a,0,n-1);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	

	return 0;
}
/*

 Recursive C program for merge sort 
#include<stdlib.h> 
#include<stdio.h> 
  
Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] 
void merge(int arr[], int l, int m, int r); 
  
l is for left index and r is right index of the sub-array 
  of arr to be sorted 
void mergeSort(int arr[], int l, int r) 
{ 
   if (l < r) 
   { 
      int m = l+(r-l)/2; //Same as (l+r)/2 but avoids overflow for large l & h 
      mergeSort(arr, l, m); 
      mergeSort(arr, m+1, r); 
      merge(arr, l, m, r); 
   } 
} 
  
Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
 create temp arrays 
    int L[n1], R[n2]; 
  
 Copy data to temp arrays L[] and R[] 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
 Merge the temp arrays back into arr[l..r]
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
 Copy the remaining elements of L[], if there are any 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
 Copy the remaining elements of R[], if there are any 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
*/
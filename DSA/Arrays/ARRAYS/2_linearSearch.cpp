#include<bits/stdc++.h>
using namespace std;

/*
LINEAR SEARCH
To search for a value inside the array

Traverse all the elements of the array
compare each element with the key
if key found return index else return -1

*/

int linearSearch(int a[], int n, int key)
{
	for(int i=0;i<n;i++)
	{
		if(a[i] == key)
			return i;
	}
	return -1;
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
	for (int i = 0; i < n; ++i)
		cin>>a[i];

	int key;
	cin>>key;

	cout<<"Index : "<<linearSearch(a,n,key);
	return 0;
}
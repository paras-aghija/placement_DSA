#include<bits/stdc++.h>
using namespace std;

bool compare(int a, int b)
{
	return a<b;
	//toggle sign to see variation in output
}

//we will pass our own comparator function into user defined sorting function
void bubbleSort(int a[], int n, bool (&cmp)(int a, int b))
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(cmp(a[j],a[j+1]))
				swap(a[j],a[j+1]);
		}
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
	
	bubbleSort(a,n,compare);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}
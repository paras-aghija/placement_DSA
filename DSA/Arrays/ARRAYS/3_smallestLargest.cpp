#include<bits/stdc++.h>
using namespace std;

/*
To find the largest and smallest number in an array

initialise a variable greatest to some lowest value
traverse the complete array compare each element of the array with the gratest
whenever encounter a value greater than greatest update greatest

Max integer value = INT_MAX
Min integer value = INT_MIN

*/

int largest(int a[], int n)
{
	int max = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		if(a[i]>max)
			max = a[i];
	}
	return max;
}

int smallest(int a[], int n)
{
	int min = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if(a[i]<min)
			min = a[i];
	}
	return min;
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

	cout<<"Smallest : "<<smallest(a,n)<<endl;
	cout<<"Largest : "<<largest(a,n);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;


void reArrangeArrayElements(int *a, int n)
{
	int i=0,j=0,k=0;
	while(i<n)
	{
		while(a[i]%2 == 0)
		{
			swap(a[i],a[j]);
			j+=2;
		}

		i++;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	reArrangeArrayElements(arr,n);

	for(int i:a)
		cout<<i<<" ";
	return 0;
}
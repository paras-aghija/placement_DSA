#include<bits/stdc++.h>
using namespace std;

/*
STAIRCASE SEARCH
An array is sorted along all rows and all columns
we have to search for a given element in that array

Brute Force
linear search go check for all elements

We can take advantage of the sorted rows and columns

1 4 8 10
2 5 9 15
6 16 18 20
11 17 19 23

key = 17

we can do binary search on all the rows
resulting time complexity : O(nlogn)

in matrix there are 4 corner points
00 corner is useless as 17 is greater than 1
and there are 2 paths through which we can go

33 corner is also useless in the same way

03 corner is 10
here we know 17>10 and we can only go downwards
going left is pointless
then we come to 15 and go down again to 20
now 17 is less than 20 therefore we move backwards
we come to 18 and then 16
after 16 we know 17>16 going backward is pointless
we come down and we find 17

similar can be done with 30 corner
Time Complexity appriximately = O(n)

*/

void staircasePrint(int a[][100], int n, int key)
{
	int f = 0;
	int i = 0;
	int j = n-1;

	while(i!=n-1 || j!=0)
	{
		if(a[i][j] == key)
		{
			f = 1;
			break;
		}

		if(a[i][j]>key)
			j--;

		else
			i++;
	}
	if(f==0)
		cout<<"Key not found";

	else
		cout<<"Key found at index"<<i<<" "<<j;
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
	int a[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
	int key;
	cin>>key;

	staircasePrint(a,n,key);
	return 0;
}
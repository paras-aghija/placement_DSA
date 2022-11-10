#include<bits/stdc++.h>
using namespace std;

/*
ROTATE IMAGE
Problem statement
given a 2d array of size n x n rotate the array 90 degrees

Brute foce is t play with the loops
copy the elements in another array 
to produce its rotated form
Space Complexity O(n);

We have to do in O(1) space

1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Step 1 reverse all the rows

4 3 2 1
8 7 6 5
12 11 10 9
16 15 14 13

//stl revese function

now if we transpse the above array we get the required array

4 8 12 16
3 7 11 15
2 6 10 14
1 5 9 13

we get the rotated array 90 degree rotated anticlockwise

*/

void rotate1(int a[][100], int n)
{
		
	//reverseal of rows
	for(int i=0;i<n;i++)
	{
		// int startCol = 0;
		// int endCol = n-1;	
		// while(startCol<endCol)
		// 	swap(a[i][startCol++],a[i][endCol--]);
		
		//stl reverse
		reverse(a[i],a[i]+n);
	}

	//transposing the revrsed row matrix
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i<j)
				swap(a[i][j],a[j][i]);
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
	int a[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>a[i][j]; 
	}

	rotate1(a,n);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";

		cout<<endl;
	}
	
	return 0;
}
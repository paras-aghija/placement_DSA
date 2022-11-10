#include<bits/stdc++.h>
using namespace std;
#define N 10
/*
Problem Statemet
Given a matrix of size n x n
the matrix is sorted row wise and column wise
we have to find the sum of submatrix that will give
the maximum sum for the elements present inside it


In order to define a submatrix we need to have a top left and a bottom right
We have to find the solution taking advantage of the fact that matrix is sorted row and column wise
elements in the lower right are better candidates to be the part of the required sumatrix

-5 -4 -1
-3  2  4
 2  5  8

we can make a suffix sum matrix

 8 14 11
18 19 12
15 13 8

we know that our requried sub matrix will surely have n-1,n-1 as bottom right
we just have to locate the top left
we search for the max value in the matrix and position with max val will be the top left
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif

	int a[N][N];
	int suffSum[N][N];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			suffSum[i][j] = a[i][j];
		}
	}

	for(int i=n-1;i>=0;i--)
	{
		for(int j=n-2;j>=0;j--)
			suffSum[i][j] += suffSum[i][j+1];
	}

	for(int j=n-1;j>=0;j--)
	{
		for(int i=n-2;i>=0;i--)
			suffSum[i][j] += suffSum[i+1][j];
	}
	//suffix sum array is created
	int max = INT_MIN;
	int x,y;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(suffSum[i][j]>max)
			{
				max = suffSum[i][j];
				x = i;
				y = j;
			}
		}
	}
	
	cout<<"Submatrix is :-"<<endl;
	cout<<"Top Left : "<<x<<" "<<y<<endl;
	cout<<"Bottom Right : "<<n-1<<" "<<n-1<<endl;
	cout<<"Sum : "<<max;
	return 0;
}
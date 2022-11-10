#include<bits/stdc++.h>
using namespace std;

/*
2D ARRAYS
2D array allows you to store data in tabular format
that is in form of rows and columns
indexing of both rows and columns start from 0

int a[2][3];
2d array with 2 rows and 3 columns

Inside the memory it is stored in a linear fashion
by default values in an uninitialised array are garbage values

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

	int a[5][3] = {0};
	int val = 1;
	//iterating over the array
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<3;j++)
		{
			a[i][j] = val;
			val++;
			cout<<a[i][j]<<" ";
		}

		cout<<endl;
	}

	return 0;
}
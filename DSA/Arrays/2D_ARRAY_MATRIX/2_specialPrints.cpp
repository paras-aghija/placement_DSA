#include<bits/stdc++.h>
using namespace std;

/*
WAVE PRINT
2d arrays :-

1 4 7 10
2 5 8 11
3 6 9 12

Wave print : 1,2,3,6,5,4,7,8,9,12,11,10
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

	int r,c;
	cin>>r>>c;
	int a[r][c];
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			cin>>a[i][j];
	}

	//WAVE PRINT
	//col is even we go top down
	//col is odd we go bottom up
	for(int i=0;i<c;i++)
	{
		if(i%2 == 0)
		{
			for(int j=0;j<r;j++)
				cout<<a[j][i]<<" ";
		}

		else
		{
			for(int j=r-1;j>=0;j--)
				cout<<a[j][i]<<" ";
		}
	}
	//SNAKE PATTERN
	//it is similar to wave print in horizontal fashion
	


	//SPIRAL PRINT
	//we have to traverse the array in spiral fashion
	cout<<endl<<endl;
	int startRow = 0;
	int startCol = 0;
	int endRow = r-1;
	int endCol = c-1;
 
	while(startRow<=endRow and startCol<=endCol)
	{
		//printing startRow
		for(int i=startCol; i<=endCol; i++)
			cout<<a[startRow][i]<<" ";

		startRow++;

		//printing the endCol
		for(int i=startRow; i<=endRow; i++)
			cout<<a[i][endCol]<<" ";

		endCol--;

		//print the endRow
		if(startRow<endRow){
			for(int i=endCol;i>=startCol;i--)
				cout<<a[endRow][i]<<" ";

			endRow--;
		}

		//print the startCol
		if(startCol<endCol){
			for(int i = endRow; i>=startRow; i--)
				cout<<a[i][startCol]<<" ";

			startCol++;
		}
	}

	return 0;
}
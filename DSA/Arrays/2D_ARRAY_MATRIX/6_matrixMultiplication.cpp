#include<bits/stdc++.h>
using namespace std;
#define N 10


void multiply(int mat1[][N],  
              int mat2[][N],  
              int res[][N],int n) 
{ 
    int i, j, k; 
    for (i = 0; i < n; i++) 
    { 
        for (j = 0; j < n; j++) 
        { 
            res[i][j] = 0; 
            for (k = 0; k < n; k++) 
                res[i][j] += mat1[i][k] *  
                             mat2[k][j]; 
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
	int a[N][N];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
	int b[N][N];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>b[i][j];
	}

	int c[N][N];
	multiply(a,b,c,n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<c[i][j]<<" ";

		cout<<endl;
	}
	return 0;
}
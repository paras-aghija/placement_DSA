#include<bits/stdc++.h>
using namespace std;
#define N 10

/*
Problem statemnt
Given a matrix of size n x n
we have to solve t queries where each query contains
index of top left corner and bottom right corner of a submatrix
we have to calculate the sum of the submatrix for every query

*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a[N][N];
	int preSum[N][N];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			preSum[i][j] = a[i][j];
		}
	}


	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n;j++)
			preSum[i][j] += preSum[i][j-1];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout<<preSum[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	for(int j=0;j<n;j++)
	{
		for(int i=1;i<n;i++){
			preSum[i][j] += preSum[i-1][j];
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout<<preSum[i][j]<<" ";
		cout<<endl;
	}

	int t;
	cin>>t;
	while(t--)
	{
		int tli,tlj,bri,brj;
		cin>>tli>>tlj>>bri>>brj;
		// to find sum of submatrix fo coresponding top left and bottom right
		int s1 = preSum[bri][brj];
		int s2 = (tli==0) ? 0 : preSum[tli-1][brj];
		int s3 = (tlj==0) ? 0 : preSum[bri][tlj-1];
		int s4 = (tli==0 || tlj==0) ? 0 : preSum[tli-1][tlj-1];
		cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
		int res = s1 - s2 - s3 + s4;
		cout<<res<<endl;
		
	}
	return 0;
}
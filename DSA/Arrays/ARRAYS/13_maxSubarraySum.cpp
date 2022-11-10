#include<bits/stdc++.h>
using namespace std;

/*
MAXIMUM SUBARRAY SUM
Problem Statement
Given an array find a subaarray which has the maximum sum

METHOD 1
Brute force :-
Generate sums for all the subarray and
find the maximum sum
Time Complexity : O(n^3)

METHOD 2
Cumulative Sum :-
we store some answers before solving the problem
to solve problem more efficiently
Time Complexity : O(n^2)

arr[] = 1,-3.0.-2.4.6.5.1.-6
csum[0] = a[0]
csum[i] = csum[i-1] + a[i];
csum[] = 1,-2,-2,-4,0,6,11,12,-6

sum of elements in range i to j
sum = csum[j] - csum[i-1]
in this algo extra complexity of n gnereated due to sum calculation 
have been removed and sum is now genererated in constant time
cumulative sum array is also called prefix sum array

METHOD 3
Kadane's Algorithm
Time Complexity O(n) Most efficient
Dry run code to understand

*/

//brute force
int maxSubarraySum1(int a[], int n)
{
	int maxSum = INT_MIN;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int currSum = 0;
			//this will give all pairs of i,j where j>=i
			//this loop prints elements starting from i and ending at j
			for(int k = i; k<=j; k++)
				currSum += a[k];

			if(currSum>maxSum)
				maxSum = currSum;
		}
	}
	return maxSum;
}

int maxSubarraySum2(int a[], int n)
{
	int csum[n];
	csum[0] = a[0]; 
	for(int i=1;i<n;i++)
		csum[i] = a[i] + csum[i-1];

	//cumulative sum is generated
	int maxSum = INT_MIN;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			//make all possible i j pairs for subarray
			int curSum = csum[j] - csum[i-1];
			//currSum here is computed in constant time
			if(curSum>maxSum)
				maxSum = curSum;
		}
	}
	return maxSum;
}

int maxSubarraySum3(int a[], int n)
{
	//MODIFIED KADANES ALGORITHM

	int mseh = 0;		// max sum ending here
	int mssf = INT_MIN; // max sum so far
	for(int i=0;i<n;i++)
	{
		mseh = mseh+a[i];
		if(mseh<a[i])
			mseh=a[i];
		// cout<<"max sum ending here : "<<mseh<<endl;

		mssf = max(mseh,mssf);
		// cout<<"max sum so far : "<<mssf<<endl;
		// cout<<endl;
	}

	return mssf;
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
	
	cout<<maxSubarraySum3(a,n);

	return 0;
}
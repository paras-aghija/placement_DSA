#include<bits/stdc++.h>
using namespace std;

/*
PROBLEM 1 : Equilibrium point in an array
Problem Statement
Given an integer array, find if it has an equilibrium point or not
An equilibrium point is a point if sum of elements to its right and sum of elements to its left are equal

arr[] = {3,4,8,-9,20,6}
o/p = yes (20 is eq point)

for boundary conditions
starting elements have lsum = 0 and ending element have rsum = 0 

*/
bool equilibriumPoint(int a[], int n)
{
	//we can create prefix sum and suffix sum arrays 
	//and find compare sums to right and left of the element
	//this would take O(n) TC and O(n) space
	int sum  = 0;
	for(int i=0;i<n;i++)
		sum += a[i];

	int lsum = 0;
	for(int i=0;i<n;i++)
	{
		if(lsum = sum-a[i]) // comparing lsum and rsum
			return true;

		lsum += a[i];//update lsum
		sum -= a[i]; // update sum to get rsum in if statement
	}
	return false;
}

/*
PROBLEM 2 : Max appearing in ranges
Problem Statement
Given n ranges in form of two arrays, find the maximum appearing
element in the ranges.

 L[] = {1,2,5,15}
 R[] = {5,8,7,18}

Ranges are : 1-5, 2-8, 5-7, 15-18
boundary values are included
max appearing element is 5
BRUTE FORCE
Traverse every range and keep track of all its elements
using a hash table and increase the frequency of element when found again
if number of ranges are n and max elements in ranges are m
Time Complexity = O(nm)

If values in ranges are small say <1000
initialise a vector of size 1000 where
index represent range points

L = {1,2,3}
R = {3,5,7}

arr[] = {0,1,1,1,0,0,0,0,0......} 
starting points of range incremented by 1
arr[] = {0,1,1,1,-1,0,-1,0,-1,0,0,....}
ending points + 1 decremented by 1
prefixSum = {0,1,2,3,2,2,1,1,0,0,0,....}
prefix sum of arr gives frequency of each element


*/

int maxOcc(int L[], int R[], int n)
{
	int arr[1000] = {0};
	for(int i=0;i<n;i++)
	{
		arr[L[i]]++;
		arr[R[i]+1]--;
	}
	int maxm = arr[0],res = 0;
	for(int i=1;i<1000;i++)
	{	
		arr[i] += arr[i-1];
		if(maxm < arr[i])
		{
			maxm = arr[i];
			res = i;
		}
	}
	return res;
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

	//Equilibrium Point
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	if(equilibriumPoint(a,n))
		cout<<"Equilibrium point present"<<endl;

	else
		cout<<"Equilibrium point absent"<<endl;

	//Max Occ in ranges
	cout<<endl;
	int m;
	cin>>m;
	int c[m],b[m];
	for(int i=0;i<m;i++)
		cin>>c[i];
	for(int i=0;i<m;i++)
		cin>>b[i];

	cout<<maxOcc(c,b,m);
	

	return 0;
}
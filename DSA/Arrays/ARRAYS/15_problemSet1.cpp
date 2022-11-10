#include<bits/stdc++.h>
using namespace std;

//function to print an array
void print(int a[], int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";

	cout<<endl;
}

//PROBLEM 1 : Reverse an array
void reverse(int a[], int n)
{
	int low = 0, high = n-1;
	while(low<high)
		swap(a[low++],a[high--]);
}

void reverse2(int a[], int s, int e)
{
	int low = s, high = e;
	while(low<high)
		swap(a[low++],a[high--]);	
}

//PROBLEM 2 : Rotate an array
void rotate(int a[], int n, int d = 0)
{
	//d tells the number of rotations to be done counter clockwise
	//input  : 5,8,10,12,15	d = 2
	//output : 10,12,15,5,8

	// METHOD 1 using extra space 
	//copy d elements separately shift remaining elements
	//put back d elements in order

	//METHOD 2
	//reverse elements from 0 to d-1
	//reverse elements form d to n-1
	//reverse the whole array
	//Time Complexity : O(n)
	//Space Complexity : O(1)

	reverse2(a,0,d-1);
	reverse2(a,d,n-1);
	reverse2(a,0,n-1);
}

//PROBLEM 3 : Leaders in array
//an element is a leader if there are no geater element on its right
void leader(int a[], int n)
{
	//BRUTE FORCE
	//Go to every element and check if there is a greater element to its right or not
	//Timpe Complexity : O(n^2)

	//EFFICIENT SOLUTION
	//Traverse from the end and keep track of the max element
	//last element is alway the leader
	int i = n-1;
	int max = a[i];
	cout<<max<<" ";
	while(i>=0)
	{
		if(a[i]>max)
		{
			max = a[i];
			cout<<max<<" ";
		}
		i--;
	}
	cout<<endl;
	//we can use a stack to display elements in the same order
}

//PROBLEM 4 : Trapping Rainwater
/*
PROBLEM STATEMENT
Given an array in which blocks of height a[i] are kept at position i
width of the block system is the size of the array
To find out how much water can be trapped inside the block system

arr[] = {3,0,1,2,5}
Water that can be trapped = 6 units
Draw and uderstand

Traverse the array and
for each element look for max on left of it and max on the right of it
min of these 2 - height at that posn gives water that can be trapped at that position

for 0 -> min(3,5) -> 3 -> 3-0 = 3
for 1 -> min(3,5) -> 3 -> 3-1 = 2
for 2 -> min(3,5) -> 3 -> 3-2 = 1

Sum of water that can be trapped = 6
Implementing this algo we need to find max on left and mex on right for each element
Time Complexity : O(n^2)

Efficient Implementation of above approach
Make two arrays which keep track of lmax and rmax
after building the array we can just apply the formula and calculate the ans
Time Complexity : O(n)
Space Complexity can be optimised to O(1)
*/

int rainWaterTrapped(int a[], int n)
{
	int lmax[n] = {a[0]};
	int rmax[n] = {0};
	rmax[n-1] = a[n-1];

	for(int i=1;i<n;i++)
	{
		if(a[i]>lmax[i-1])
			lmax[i] = a[i];

		else
			lmax[i] = lmax[i-1];
	}

	for(int i=n-2;i>=0;i--)
	{
		if(a[i]>a[i+1])
			rmax[i] = a[i];

		else
			rmax[i] = rmax[i+1];
	}
	print(lmax,n);
	print(rmax,n);

	int trapped = 0;
	for(int i=0;i<n;i++)
	{
		trapped += min(lmax[i],rmax[i]) - a[i];
	}

	return trapped;
}

//PROBLEM 5 : Stock buy and sell
/*
Problem statement
Stock prices for n given days are given
to find such buy and sell pairs so that we get maximum profit
to display the maximum profit possible

arr[] = {1,5,3,8,12}

1,5  -> 4
3,12 -> 9

Max profit possible

arr2[] = {5,4,3,2,1}
max profit = 0

arr3[] = {1,2,3,4,5}
max profit = 5 - 1 = 4

To find the profit we just need to keep track of local maxima and local mimima
sum of differences between consecutive local maximas and local minimas is total profit

arr[] = {1,5,3,8,12}
local minimas : 1 3
local maximas : 5 12

subtract element of above 2 arrays index by index and sum all differences to find the sum
*/ 

int stockBuySell(int a[], int n)
{
	//just looking for increasing paths in the graph
	//and adding up the difference in prices to diff variable
	int diff = 0;
	for(int i=1;i<n;i++)
	{
		if(a[i]>a[i-1])
			diff += a[i] - a[i-1]; 
	}
	return diff;
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
	
	//reversing the array
	print(a,n);
	reverse(a,n);
	print(a,n);
	reverse(a,n);

	//rotating the array
	cout<<endl;
	print(a,n);
	rotate(a,n,2);
	print(a,n);

	//leaders in an array
	cout<<endl;
	print(a,n);
	leader(a,n);

	//trapping rainwater problemrrrr
	cout<<endl;
	int m;
	cin>>m;
	int b[m];
	for(int i=0;i<m;i++)
		cin>>b[i];
	
	print(b,n);
	cout<<rainWaterTrapped(b,m)<<endl;

	cout<<endl;
	int t;
	cin>>t;
	int c[t];
	for(int i=0;i<t;i++)
		cin>>c[i];

	cout<<stockBuySell(c,n);

	
	return 0;
}
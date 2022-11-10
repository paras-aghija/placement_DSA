#include<bits/stdc++.h>
using namespace std;

/*
SUM OF PAIR PROBLEM
Problem Statement
Given a sorted array to find the pair of elements that sum to k

METHOD 1 :-
BRUTE FORCE
Two for loops -> compute sum of all pairs
compare with the given sum
Time Complexity : O(n^2)

METHOD 1 Enhanced :-
Instead of finding sum for all pairs
we can traverse the array using one loop
for each element x we can search for element (rsum-x) inside the array
Time complexity : O(nlogn)

METHOD 2:-
TWO POINTER APROACH
Making use of the fact that array is sorted
we make two pointers sone pointing to starting element and other pointing to ending element
arr[] = 1,3,5,9,10,11,12,13
rsum = 15 //sum required

i -> 1
j -> 13
sum = 14 < 15
therefore we move the left ptr that is i
i -> 3
j -> 13
sum = 16 > 15
now we move the right pointer towards left as rsum is less than cursum
i -> 3
j -> 12
sum = 15 == 15
pair found
after one pair found change both i and j to find out if more pairs are present or not
i -> 5
j -> 11
sum = 16 > 15
i -> 5
j -> 10
sum = 15 == 15 one more pair found
and so the process goes on until i<j
if i becomes >= j then loop terminates

Time Complexity : O(n)

*/

void pairSum(int a[], int n, int key)
{
	int f = 0;
	int i=0,j=n-1;
	int sum = 0;
	while(i<j)
	{
		sum = a[i] + a[j];

		if(sum == key)
		{
			f = 1;
			cout<<a[i]<<" "<<a[j]<<endl;
			i++;
			j--;
		}

		else if(sum>key)
			j--;

		else if(sum<key)
			i++;
	}
	if(f == 0)
		cout<<"No Pair found";
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

	int key;
	cin>>key;
	pairSum(a,n,key);
	
	return 0;
}
#include<iostream>
#include<algorithm> //header file containing sort function
using namespace std;

//Comparator function to sort in decreasing order
bool compare(int a, int b)
{
	cout<<"Comparing "<<a<<" and "<<b<<endl;
	return a > b;
}
/*
How comparators work
every sorting algo will have some comparison using > or <
compare just tells sort algorithm that use compare function provided by the user
to compare wherever needed and > and < can therefore be toggled

we can write out own comparator function
example we can also compare numbers based on number of digits
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

	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	// sort(a,a+n);
	
	//this is most efficient in terms of time complexity
	//takes starting address and ending address of the container
	//ending address is not inclusive in sorting
	
	//to sort in decreasing order
	sort(a, a+n, compare);
	//function compare is passed as a parameter to another function

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";

	return 0;
}
#include<bits/stdc++.h>
using namespace std;

/*
Arrays in c++ are used to store homogenous values
Initially array when declared contains garbag values

Syntax :-
 	Datatype varName[size];

Accessing an element of an array takes constant time
Array elements can be directly accessed using the index values inside square brackets
We can iterate over the array using loops
last index of an array =  size - 1

ADVANTAGES OF ARRAYS :-

	1. Random Access : element can be accessed in constant time
	2. Cache Friendliness

DISADVANTAGES OF ARRAYS :-

	1. Fixed Size

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

	int a[10] = {0};
	//All elements of the array are initialised as 0
	for (int i = 0; i < 7; ++i)
		cout<<a[i]<<" ";

	cout<<endl;
	int b[5] = {5};
	b[3] = 7;
	//initialises first element as 5 and rest as 0
	for (int i = 0; i < 5; ++i)
		cout<<b[i]<<" ";

	cout<<endl;
	int c[5] = {1,2,3};
	for(int i = 0; i<5; i++)
		cout<<c[i]<<" ";

	// takin input in the array
	int d[5];
	for (int i = 0; i < 5; ++i)
		cin>>d[i];

	cout<<endl;
	for (int i = 0; i < 5; ++i)
		cout<<d[i]<<" ";

	cout<<endl<<sizeof(d);
	//each bucket is of the size 4 and their are 5 buckets
	cout<<endl;
	cout<<"Size of  d : "<<(sizeof(d)/sizeof(d[0]));


	return 0;
}
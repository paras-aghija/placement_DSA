#include<bits/stdc++.h>
using namespace std;

class Test
{
	int *ptr;

public:

	// object must be passed by reference
	// Test(const Test &t)
	// {
	// 	int val = *(t.ptr);
	// 	ptr = new int(val);
	// }
	//own defined copy constructor for deep copy
	//do not give output 20 20

	Test(int x)
	{
		ptr = new int(x);
	}
	void set(int x)
	{
		*ptr = x;
	}
	void print()
	{
		cout<<*ptr<<endl;
	}
	
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif

	Test t1(10);
	Test t2(t1); // compiler by default creates a copy constructor
	Test t3 = t2; // this is also a copy constructor call
	t2.print();
	t3.print();
	//Test t4;
	//t4 = t1 // this is not a copy constructor call

	t2.set(20);
	t1.print();
	t2.print(); // o/p is 20 20 because of default copy constructor

	//default copy constructor does a shallow copy
	//to make a deep copy we must have our own copy constructor
	return 0;
}
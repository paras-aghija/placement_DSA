#include<bits/stdc++.h>
using namespace std;

class Base
{
protected:
	int x;

public:
	Base(int a) : x(a)
	{ cout<<"Base"<<endl; }
	
};

class Derived : public Base
{
private:
	int y;

public:
	Derived(int a, int b) : Base(a), y(b)
	{ cout<<"Derived"<<endl; }
	
	void print()
	{ cout<<x<<" "<<y<<endl; }
	
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

	Derived d(10,2);
	d.print();

	return 0;
}
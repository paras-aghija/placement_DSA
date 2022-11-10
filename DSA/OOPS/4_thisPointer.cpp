#include<bits/stdc++.h>
using namespace std;

class Point
{
private:
	int x,y;

public:

	Point() : x(0),y(0) {}
	Point(int x1, int y1)
	{
		x = x1;
		y = y1;

		//internalycompiler compiles above lines as
		//this->x = x1;
		//this->y = y1;
		//this pointer can be also used to avoid name collission of class data and function parameters
		// this is a special pointer pointing to the object on which function is called
		//THIS pointer can also be used in chaining functions
		//NOTE : this pointer is a constant pointer
	}

	Point& setx(int x) // return type os a reference to the same class
	{
		this->x = x;
		return *this; // same class returned as reference
	}

	Point& sety(int y)
	{
		this->y = y;
		return *this;
	}
	void print()
	{
		cout<<x<<" "<<y<<endl;
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

	Point p1(10,20);
	p1.print();
	p1.setx(2).sety(5); // chain function call
	p1.print();
	//p1.setx(2) returns the same class as reference over which sety function is called
	//in cout statements too this concept is used
	//	(cout<<x)<<" "<<y;
	//	this returns an object of ostream type after inserting x in stdout
	//	over the returned object of ostream type we can again display further elements
	//cout is also an example of chaining

	return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Point
{
private:
	int x,y;

public:
	// Point()
	// {
	// 	x = 0;
	// 	y = 0;
	// }

	// Point(int x1, int y1)
	// {
	// 	x = x1;
	// 	y = y1;
	// }

	//defining pointers using initialiser list

	Point() : x(0),y(0) {}
	Point(int x1, int y1) : x(x1),y(y1) {}

	//initialiser list must be prefered due to efficient performance
	void print()
	{
		cout<<x<<" "<<y<<endl;
	}
	
};

class Test
{
public:
	Test(){cout<<"Default"<<endl;}
	Test(int x){cout<<"Parameterised"<<endl;}
};

class Main
{
	Test t; // this statement is executed first therefore print defalut
public:
	Main()
	{
		t = Test(10); // prints parameterised 2nd initialisation
	}	
};

class Main2
{
	Test t; // this statement is executed first therefore print defalut
public:
	Main2() : t(10) {} //prints only parameterised
	//single initialisation takes place;
	
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

	Point p1, p2(10,20);
	p1.print();
	p2.print();
	Point *ptr = new Point(5,7);
	ptr->print();

	Main m;
	Main2 n;
	return 0;
}
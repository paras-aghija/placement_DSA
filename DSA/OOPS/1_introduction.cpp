#include<bits/stdc++.h>	
using namespace std;


//polymorphism is 1 name different functionalities
//encapsulation is bundelling all the data memebers and methods into a single unit Class
class Complex
{
//private members cannot be accessed outside the class
//only class methods can access content inside private
//this technique of making functionalities privste and showing only 
//required information to the user is called abstraction
//hiding internal details
private:
	int real;
	int imag;

public:

	//constructors are overloaded
	Complex() // constructor of te class
	{
		real = 0;
		imag = 0;
	}

	Complex(int r,int i) // parameterized constructor
	{
		real = r;
		imag = i;
	}

	void display()
	{
		cout<<real<<" + i"<<imag<<endl;
	}

	~Complex() // destructor
	{
		cout<<"Object Scope Finished"<<endl;
	}

	//objects are distructed in reverse order of their consruction
	//distructors are also called when we delete a dynamically created class object
	//destructors are also created by default

	int retreal()
	{return real;}

	int retimag()
	{return imag;}
	
};

Complex complexSum(Complex a, Complex b)
{
	Complex c((a.retreal()+b.retreal()),a.retimag()+b.retimag());
	return c;
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

	Complex c1(2,5); // Object of a class
	c1.display();
	Complex c2(4,7);
	c2.display();
	Complex c3 = complexSum(c1,c2);
	c3.display();
	return 0;
}
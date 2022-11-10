#include<bits/stdc++.h>
using namespace std;

/*
Virtual Function

A base class reference or pointer can point to derived class object

*/
class Base {};
class Derived : public Base {};

class Base2 {

public:
	void print(){	cout<<"Base"<<endl;	}
	virtual void print2(){ cout<<"Base"<<endl; }
};
class Derived2 : public Base2 {

public:
	void print(){	cout<<"Derived"<<endl;	}
	// void print2(){ cout<<"Derived"<<endl; }
	//better syntax
	void print2() override{ cout<<"Derived"<<endl; }
};

/*
In OOPs if the derrived class have a function with same name as in base class
then it is function overriding

Due to virtual keyword it is decided at runtime which fuction is to be called
at runtime it is decided that to which object is the pointer pointing to which is calling the function
this is an example of runtime polymorphism

Function overloading is an example of compile time polymorphism

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

	// Base *b = new Derived;
	Derived d;
	Base &b = d;	
	//both lines do same work below one is using a reference
	//above line uses a pointer

	Base2 b2;
	Derived2 d2;
	b2.print();
	d2.print();
	Base2 *ptr = &d2;
	ptr->print();
	//here output is Base becaus ptr is of Base type
	//therefor to overcome this that type of function should not decide function being called
	//rathar it should be decided by the object it is pointing to
	//we use vitual keyword
	ptr->print2();
	//virtual functions makes sure that the right fucntion call is made

	return 0;
}

/*
WORKING OF VIRTUAL FUNCTION

Compilers use 2 things to implement virtual functions inside them

	1- VPTR which is maintained with every object
	2- VTABLE which is there for every class
	And VPTR points ot VTABLE

when you create an object of a class the compiler adds some cod o the constructor
this code sets Vptr to Vtable of the class
Vtable stores addresses of all virtual functions of the class
when a call to an overridden function is made compiler goes to the vptr of the object
using vptr it fins the vtable of the class
and then using vtable it finds the address of the function being called

when we called print of derived
compiler goes to the vptr of the object ptr is pointing to (derived)
therefore it goes to vtable of the derived class and calls the appropriate function

*/
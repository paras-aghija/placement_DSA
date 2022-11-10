#include<bits/stdc++.h>
using namespace std;

/*
Protected access specifier

public -> accessible anywhere outside the class
private -> not accessible anywhere outside the class
protected -> not accessible outside except in inherited classes

*/

class Person
{
protected:
	string name;
	int id;

public:
	Person()
	{
		name = "noname";
		id = 0;
	}

	Person(string s, int i)
	{
		name = s;
		id = i;
	}
	
	
};

//access specifier basically tell the content derrived from the base class will be derrived to whidh
//access mode in the child class
class Student : public Person // access specifier here tells the level of access allowed to the base class
{
	int marks;

public:
	Student()
	{
		marks = 0;
	}

	Student(string s, int i, int m) : marks(m)
	{
		name = s;
		id = i;
	}

	void print()
	{
		cout<<name<<" "<<id<<" "<<marks<<endl;
	}
	
};
/*
if access specifier is public
protected content of base class remains protected inside the child class
and public content of the parent class is inhereted to public section of the child class

if access specifier is private then
public and protected sections of the base class ae inhereted to private sections of the child class

similarly for protected
public and protected sections are inherited to the protected section of the child class

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

	Student s("Rohan",217,98);
	s.print();
	return 0;
}
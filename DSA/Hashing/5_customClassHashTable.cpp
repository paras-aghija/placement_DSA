#include<bits/stdc++.h>
using namespace std;


/*
We have to make a hash table where kay is an object if student class
and value is suppose an integer then to achieve this
we have to make out own hash function
also we have to set a criteria if two objects are same or not to avoid multiple insertions
*/
class Student
{

public:

	string firstname;
	string lastname;
	string rollno;

	Student(string f, string l, string no)
	{
		firstname = f;
		lastname = l;
		rollno = no;
	}

	bool operator==(const Student &s) const
	{
		return rollno == s.rollno;
	}
	
};

class HashFn
{
public:
	
	//this is an unsigned int type of datatype in c++
	//it is used to represent size of some memory in bytes
	//this is return type required for stl defined hash function
	size_t operator()(const Student &s) const
	{
		return s.firstname.length() + s.lastname.length();
	}
	
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_map<Student,int,HashFn> student_map;
	Student s1("Prateek","Narang","010");
	Student s2("Rahul","Kumar","023");
	Student s3("Prateek","Gupta","030");
	Student s4("Rahul","Kumar","120");

	student_map[s1] = 100;
	student_map[s2] = 120;
	student_map[s3] = 11;
	student_map[s4] = 45;

	for(auto s : student_map)
		cout<<s.first.firstname<<" "<<s.first.rollno<<" "<<s.second<<endl;

	cout<<student_map[s4]<<endl;

	return 0;
}
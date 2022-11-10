#include<iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

/*
phonebook

X : 981...., 782....
Y : 882...., 728....

*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_map< string,vector<string> > phonebook;

	phonebook["Rahul"].push_back("9110156627");
	phonebook["Rahul"].push_back("7829825729");
	phonebook["Kajal"].push_back("8297262920");
	phonebook["Kajal"].push_back("2820016729");
	phonebook["Kajal"].push_back("8298266226");
	phonebook["Sumit"].push_back("9263802862");

	for(auto p : phonebook)
	{
		cout<<"Name: "<<p.first<<endl;
		for(string s : p.second)
		{
			cout<<s<<",";
		}
		cout<<endl;


	}

	
	return 0;
}
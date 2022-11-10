#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class Node
{

public:
	string key;
	T value;
	Node<T> *next;

	Node(string key, T val)
	{
		this->key = key;
		value = val;
		next = NULL;
	}

	~Node()
	{
		if(next!=NULL)
			delete next;
	}
};

template<typename T>
class Hashtable
{
	Node<T> **table; //pointer to an array of pointers
	int curr_size;
	int table_size;

	int hashFn(string key)
	{
		int idx = 0;
		int p = 1;
		for(int j=0;j<key.length();j++)
		{
			idx = idx + (key[j]*p) % table_size;
			idx = idx % table_size;
			p = (p*27) % table_size;
			// to prevent overflow
		}

		return idx;
	}

	void rehash()
	{
		Node<T> **oldTable = table;
		int oldTableSize = table_size;
		table_size = 2*table_size;
		//approximation can find the next prime number too

		table = new Node<T>*[table_size];
		for(int i=0;i<table_size;i++)
			table[i] = NULL;

		curr_size = 0;

		//shift the elements from old table to new table
		for(int i=0;i<oldTableSize;i++)
		{
			Node<T>*temp = oldTable[i];
			while(temp!=NULL)
			{	
				insert(temp->key,temp->value);
				temp = temp->next;
			}
			//removing the old table from the memory
			//1st deletion of the internal linked list
			if(oldTable[i]!=NULL)
				delete oldTable[i];

			//deletes the linked list at the ith position in the table
			//destructors auto delets the whole linked list using its recursive deletion
		}		

		delete [] oldTable;
		//deletes the old table containing head pointers from the memory
	}

public:

	Hashtable(int ts=7)
	{
		table_size = ts;
		table = new Node<T>*[table_size];
		//array of table_size is created 
		//which holds heads of linked list of node type
		//Head is of Node<T> * type
		curr_size = 0;
		for(int i=0;i<table_size;i++)
			table[i] = NULL;

		//initialiseing all head pointers inside the table as NULL
	}

	void insert(string key, T value)
	{
		// key -> hash function -> hash value -> table
		int idx = hashFn(key);

		Node<T> *n = new Node<T>(key,value);
		//insert at head of the linked list at idx
		n->next = table[idx];
		//put the initial starting node to next of n
		table[idx] = n;
		//make n the starting node
		curr_size++;

		//rehash.... 
		float load_factor = curr_size/(1.0*table_size);
		if(load_factor > 0.7)
		{
			cout<<"Rehashing"<<endl;
			cout<<"load_factor : "<<load_factor<<endl;
			cout<<"curr_size : "<<curr_size<<endl;
			cout<<"table_size : "<<table_size<<endl;
			rehash();
		}

	}

	void print()
	{
		for(int i=0;i<table_size;i++)
		{
			cout<<"Bucket "<<i<<" -> ";
			Node<T> *temp = table[i];
			while(temp!=NULL)
			{
				cout<<temp->key<<"->";
				temp = temp->next;
			}
			cout<<endl;
		}

	}

	T* search(string key)
	{
		int idx = hashFn(key);
		Node<T> *temp = table[idx];
		while(temp!=NULL)
		{
			if(temp->key == key)
				return &temp->value;

			temp = temp->next;
		}

		return NULL;
	}

	T& operator[](string key)
	{
		T *f = search(key);
		if(f == NULL)
		{
			//insert key,value pair in the hash table
			T garbage;
			insert(key,garbage);
			f = search(key);
			//f is a pointer pointing to value of inserted key
			//f is pointing to the garbage value
		}
		return *f;
	}

	void erase(string key)
	{
		int idx = hashFn(key);
		Node<T> *temp = table[idx];
		if(table[idx] == NULL)
			return;

		else if(temp->next == NULL and temp->key == key)
		{
			table[idx] = NULL;
			delete temp;
		}

		while(temp->next!=NULL)
		{
			if(temp->next->key == key)
			{
				Node<T> *t = temp->next;
				temp->next = t->next;
				t->next = NULL;
				delete t;
			}
		}
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	Hashtable<int> price_menu;
	price_menu.insert("Burger",120);
	price_menu.insert("Pepsi",50);
	price_menu.insert("BurgerPizza",180);
	price_menu.insert("Noodles",80);
	price_menu.insert("Coke",40); //collides with pepsi

	price_menu.print();

	int *price = price_menu.search("Noodle");
	if(price == NULL)
		cout<<"Not Found"<<endl;

	else
		cout<<"Price is "<<*price<<endl;

	price_menu.erase("Coke");
	cout<<endl;
	price_menu.print();

	price_menu["Dosa"] = 60;
	price_menu["Dosa"] += 10;
	cout<<"\nPrice of Dosa : "<<price_menu["Dosa"]<<endl;

	cout<<endl;
	price_menu.print();

	return 0;
}
#include<bits/stdc++.h>
using namespace std;

/*
DOUBLY LINKED LIST

Maintains a previous pointer as well
backward trsversal is also possible
*/

struct Node
{
	int data;
	Node *next;
	Node *prev;

	Node(int x)
	{
		data = x;
		next = NULL;
		prev = NULL;
	}
};

class DLL
{

private : 
	
	Node *head, *tail;

public :
	DLL()
	{
		head = NULL;
		tail = NULL;
	}

	void insertAtHead(int x)
	{
		Node *temp = new Node(x);
		if(head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
	}

	void insertAtTail(int x)
	{
		Node *temp = new Node(x);
		if(head == NULL)
		{
			head = temp;
			tail = temp;
		}

		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
	}

	void print()
	{
		Node *temp = head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}

	void deletenth(int n)
	{

		Node *temp = head;
		while(--n)
			temp = temp->next;

		// cout<<temp->data;
		if(temp == head)
		{

			if(temp == tail)
			{
				tail = NULL;
			}

			Node *t = head;
			head = t->next;
			head->prev = NULL;
			free(t);
		}

		else if(temp == tail)
		{
			Node *t = tail;
			tail = t->prev;
			tail->next = NULL;
			free(t);
		}

		else
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp); 
		}


	}

	void headTail()
	{
		cout<<"Head : "<<head<<endl;
		cout<<"Tail : "<<tail<<endl;
	}

	void reversePrint()
	{
		Node *temp = tail;
		while(temp != NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->prev;
		}
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

	DLL ll;
	ll.insertAtHead(3);
	ll.insertAtHead(7);
	ll.insertAtTail(9);
	ll.print();
	ll.insertAtTail(4);
	ll.print();
	ll.deletenth(3);
	ll.print();
	ll.deletenth(1);
	ll.print();
	ll.deletenth(2);
	ll.print();
	ll.insertAtTail(4);
	ll.insertAtTail(5);
	ll.insertAtTail(6);
	ll.print();
	ll.reversePrint();





	return 0;
}
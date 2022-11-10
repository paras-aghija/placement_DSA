#include<bits/stdc++.h>
using namespace std;

//INCOMPLETE

struct Node
{
	int data;
	Node *next;

	Node(int x)
	{
		data = x;
		next = NULL;
	}
};

class CLL
{
private :

	Node *tail, *head;

public: 

	CLL()
	{	
		tail = NULL;
		head = NULL;
	}

	void add(int x)
	{
		Node *temp = new Node(x);
		if(head == NULL)
		{
			tail = temp;
			head = temp;
			tail->next = head;
		}
		else
		{
			tail->next = temp;
			tail = temp;
			tail->next = head;
		}
	}

	void find(int x)
	{
		Node *temp = head;
		int n = 1, f = 0;
		do{
			if(temp->data == x)
			{
				f = 1;
				cout<<"Data found at position "<<n<<endl;
				break;
			}
			temp = temp->next;
			n++;
		}while(temp!=head);
		if(f == 0)
			cout<<"Data not found"<<endl;
	}

	void deleteElement(int x)
	{
		int f = 0;
		Node *temp = head;
		do{
			if((temp->next)->data == x)
			{
				Node *t = temp->next;
				if(t == head)
				{
					if(t == tail)
					{
						free(t);
						head = NULL;
						tail = NULL;
					}
					temp->next = t->next;
					head = t->next;
					free(t);
				}

				else if(t == tail)
				{
					temp->next = t->next;
					tail = temp;
					free(t);
				}

				else
				{
					temp->next = t->next;
					free(t);
				}
			}
			temp = temp->next;

		}while(temp!=head);
	}

	void print()
	{
		Node *temp = head;
		do
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}while(temp != head);
		cout<<endl;
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

	CLL ll;
	ll.add(1);
	ll.add(2);
	ll.add(3);
	ll.add(4);
	ll.print();
	ll.add(7);
	ll.print();
	ll.find(7);
	ll.deleteElement(3);
	ll.print();
	return 0;
}
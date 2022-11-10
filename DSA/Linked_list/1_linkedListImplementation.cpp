#include<bits/stdc++.h>
using namespace std;

/*
LINKED LIST

Advantages over arrays

	- Dynamic Size
	- Ease of insertion and deletion

Disadvantages

	- Random access not alowed
	- Extra memory space for pointer is required
	- Not cache friendly

*/

struct Node //singly linked list
{
	int key;
	Node *next;

	Node(int x) // constructor
	{
		key = x;
		next = NULL;  
	}
};

struct LList
{
	Node *head, *tail;
	LList()
	{
		head = NULL;
		tail = NULL;
	}

	void insertAtBegin(int x)
	{
		Node *temp = new Node(x);
		temp->next = head;
		head = temp;

		if(tail == NULL)
			tail=head;
	}

	void insertAtEnd(int x)
	{
		if(head == NULL)
			insertAtBegin(x);

		else
		{
			Node *temp = new Node(x);
			tail->next = temp;
			tail = temp;
		}
	}

	void insertAfter(int n, int x)
	{
		Node *t = head;
		while(--n)
			t = t->next;

		Node *temp = new Node(x);
		temp->next = t->next;
		t->next = temp;
	}

	void print()
	{
		Node *temp = head;
		while(temp!=NULL)
		{
			cout<<(temp->key)<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}

	void middleElement()
	{
		Node *slow = head, *fast = head;
		while(fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		//when fast reaches end slow reaches the middle
		cout<<"Middle element is : "<<slow->key<<endl;
	}

	int length()
	{
		Node *temp = head;
		int count = 0;
		while(temp!=NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}

	void nthNodeFromEnd(int n)
	{
		Node *temp = head;
		while(n--)
			temp = temp->next;

		Node *t = head;
		while(temp!=NULL)
		{
			temp = temp->next;
			t = t->next;
		}

		cout<<"Nth from end : "<<t->key<<endl;
	}

	void iterativeReverse()
	{
		Node *curr = head, *prev = NULL;
		while(curr!=NULL)
		{
			Node *next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}

	void recursiveReverse(Node *curr, Node *prev)
	{
		if(curr == NULL)
			return;

		if(curr->next == NULL)//at last node
		{
			head = curr;
			curr->next = prev;
		}

		else
		{
			Node *next = curr->next;
			curr->next = prev;
			recursiveReverse(next,curr);
		}
	}

	void deletenth(int n)
	{
		
		Node *temp = head;
		if(n==1)
		{
			head = temp->next;
			free(temp);
			return;
		}

		n--;
		while(--n)
			temp = temp->next;
		//temp points to (n-1)th node
		// cout<<temp->key<<endl;

		Node *t = temp->next;
		temp->next = t->next;
		free(t);
	}

	

};

void reversePrint(Node *temp)
{
	if(temp == NULL)
		return;
	reversePrint(temp->next);
	cout<<temp->key<<" ";
}

/*
detect loop in a linked list
circular linkage present or not

Algo 1 
	check for each node if null or same node is achieved or not
	TC = O(n^2) in Worst case

Algo 2 HASH TABLE
	Put address of every node in hash table
	and check if next of any node is present in hash table or not
	TC = O(n)

Algo 3 FLOYD'S ALGORITHM

	Based on fast and slow pointer approach
	fast pointer moves at double speed
	if loop cycle is present in the linked list then fast and slow will surely meet 
	Example
		10->20->30->40->links again to 20 forming a cycle

	suppose cycle starts at Tth node
	at the moment slow is at T and fast is k nodes far from slow inside the cycle
	after next iteration slow will move fwd by 1 and fast by 2
	distance between fast and slow in primary path is increasing by 1
	distance between fast and slow in secondary path is decreasing by 1
	after each iteration therefore fast speed is double of slow
	therefore fast and slow will surely meet
	TC = O(n)

*/

void loopCheck(Node *head)
{
	Node *fast = head, *slow = head;
	while(slow != NULL)
	{
		if(fast == NULL || fast->next == NULL)
		{
			cout<<"No loop present"<<endl;
			break;
		}
		else
		{
			fast = fast->next->next;
			slow = slow->next;

			if(slow==fast)
			{
				cout<<"Loop detected"<<endl;
				break;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	LList ll;
	ll.insertAtBegin(11);
	ll.insertAtEnd(7);
	ll.insertAtEnd(2);
	ll.insertAtEnd(5);
	ll.print();
	ll.insertAfter(3,0);
	ll.print();
	ll.insertAtBegin(4);
	ll.insertAtEnd(1);
	ll.print();
	ll.middleElement();
	cout<<"Length of LL : "<<ll.length()<<endl;
	ll.nthNodeFromEnd(3);
	ll.iterativeReverse();
	ll.print();
	ll.recursiveReverse(ll.head,NULL);
	ll.print();
	loopCheck(ll.head);
	reversePrint(ll.head);
	cout<<endl;
	ll.print();
	ll.deletenth(4);
	ll.print();
	ll.deletenth(1);
	ll.print();


	return 0;
}
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

*****************************************************************/

Node* merge(Node *a, Node * b){
    Node *ans=new Node(0), *temp=ans;
    while(a!=NULL and b!=NULL){
        if(a->data < b->data){
            temp->child = a;
            temp = temp->child;
            a = a->child;
        } else {
            temp->child = b;
            temp = temp->child;
            b = b->child;
        }
    }
    if(a!=NULL) temp->child = a;
    else temp->child = b;
    return ans->child;
}
Node* flattenLinkedList(Node* head) 
{
    if(head->next==NULL) return head;
    // Write your code here
    head->next = flattenLinkedList(head->next);
    head = merge(head, head->next);
    head->next=NULL;
    return head;
}

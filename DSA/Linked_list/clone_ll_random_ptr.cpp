/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        Node *temp = head;
        while(temp){
            m[temp] = new Node(temp->val);
            temp = temp->next;
        }
        Node *ans = m[head];
        temp = head;
        while(temp){
            m[temp]->next = m[temp->next];
            m[temp]->random = m[temp->random];
            temp = temp->next;
        }
        return ans;
    }
};

// Without HashTable space

// make copies of nodes just next to them
// one iteration for making copies
// one iteration for assigning 

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp = head;
        while(temp!=NULL){
            Node *n = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = n;
            temp = n;
        }
        temp = head;
        while(temp){
            if(temp->random) temp->next->random = temp->random->next;
            temp=temp->next->next;
        }
        Node *ans = head->next;
        Node *a = head;
        Node *b = head->next;
        while(b->next){
            Node *an = a->next->next;
            Node *bn = b->next->next;            
            a->next = an;
            b->next = bn;
            a=a->next;
            b=b->next;
        }
        a->next=NULL;
        b->next=NULL;
        return ans;
    }
};
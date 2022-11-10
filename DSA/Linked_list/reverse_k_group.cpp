/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
        
        ListNode *c=head;
        ListNode *p = NULL, *n;
        
        while(c != NULL){
            n = c->next;
            c->next = p;
            p=c;
            c=n;
        }
        return p;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        int i=1;
        ListNode *temp = head;
        while(i<k and temp->next!=NULL){
            temp = temp->next;
            i++;
        }
        if(i!=k) return head;
        ListNode *fwd = reverseKGroup(temp->next, k);
        temp->next = NULL;
        ListNode *a = reverseList(head);
        temp = a;
        while(temp->next!=NULL) temp = temp->next;
        temp->next = fwd;
        return a;
    }
};
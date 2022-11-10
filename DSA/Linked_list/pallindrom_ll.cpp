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
    
    ListNode* reverse(ListNode *head){
        ListNode *p=NULL, *c=head, *n;
        while(c!=NULL){
            n=c->next;
            c->next = p;
            p=c;
            c=n;
        }
        return p;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *s, *f, *p;
        s=f=p=head;
        while(f->next!=NULL and f->next->next!=NULL){
            f=f->next->next;
            s=s->next;
        }
        s->next = reverse(s->next);
        if(s->next==NULL) return p->val==s->val;
        s=s->next;
        while(s!=NULL){
            if(s->val != p->val) return 0;
            s=s->next;
            p=p->next;
        }
        return 1;
        
    }
};
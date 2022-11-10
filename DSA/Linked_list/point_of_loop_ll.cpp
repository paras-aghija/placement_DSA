/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL or head->next==NULL) return NULL;
        ListNode *f, *s;
        f=s=head;
        while(f and f->next){
            f=f->next->next;
            s=s->next;
            if(f==s) break;
        }
        if(f==NULL or f->next==NULL) return NULL;
        f = head;
        while(f!=s){
            f=f->next;
            s=s->next;
        }
        return s;
    }
};
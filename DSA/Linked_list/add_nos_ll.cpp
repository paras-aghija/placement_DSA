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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode *head=NULL;
        ListNode *p1=l1, *p2=l2, *p3;
        while(p1!=NULL and p2!=NULL){
            int ca = p1->val + p2->val + c;
            c = ca/10;
            ca %=10;
            if(head==NULL){
                head = new ListNode(ca);
                p3=head;
            } 
            else{
                p3->next = new ListNode(ca);
                p3 = p3->next;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1!=NULL){
            int ca = p1->val + c;
            c = ca/10;
            ca%=10;
            p3->next = new ListNode(ca);
            p3 = p3->next;
            p1 = p1->next;
        }
        while(p2!=NULL){
            int ca = p2->val + c;
            c = ca/10;
            ca%=10;
            p3->next = new ListNode(ca);
            p3 = p3->next;
            p2 = p2->next;
        }
        if(c!=0){
            p3->next = new ListNode(c);
        }
        return head;
    }
};
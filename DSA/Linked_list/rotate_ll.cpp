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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or head->next==NULL) return head;
        int len=0;
        ListNode *temp = head, *tail;
        while(temp!=NULL){
            tail=temp;
            temp = temp->next;
            len++;
        }
        k=k%len;
        if(k==0) return head;
        int x = len-k-1;
        temp=head;
        while(x--){
            temp = temp->next;
        }
        ListNode *a = temp->next;
        temp->next=NULL;
        tail->next=head;
        return a;
    }
};
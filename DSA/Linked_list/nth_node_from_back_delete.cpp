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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL) return NULL;
        ListNode *a, *b;
        a=b=head;
        while(n--){
            a=a->next;
        }
        if(a==NULL){
            return head->next;
        }
        while(a->next!=NULL){
            a = a->next;
            b = b->next;
        }
        
        b->next = b->next->next;
        return head;
    }
};
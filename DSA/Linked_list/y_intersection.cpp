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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> s;
        ListNode *a=headA;
        while(a!=NULL){
            s.insert(a);
            a = a->next;
        }
        a=headB;
        while(a!=NULL){
            if(s.find(a)!=s.end()) return a;
            a=a->next;
        }
        return NULL;
    }
};
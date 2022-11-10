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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans, *temp, *a, *b;
        ans = NULL;
        a=list1;
        b=list2;
        while(a!=NULL and b!=NULL){
            if(a->val <= b->val){
                if(ans==NULL){
                    ans = new ListNode(a->val);
                    a = a->next;
                    temp = ans;
                } else{
                    temp->next = new ListNode(a->val);
                    temp = temp->next;
                    a = a->next;
                }
            } else {
                if(ans==NULL){
                    ans = new ListNode(b->val);
                    b = b->next;
                    temp = ans;
                } else{
                    temp->next = new ListNode(b->val);
                    temp = temp->next;
                    b = b->next;
                }
            }
        }
        while(a!=NULL){
            if(ans==NULL){
                    ans = new ListNode(a->val);
                    a = a->next;
                    temp = ans;
                } else{
                    temp->next = new ListNode(a->val);
                    temp = temp->next;
                    a = a->next;
                }
        }
        while(b!=NULL){
            if(ans==NULL){
                    ans = new ListNode(b->val);
                    b = b->next;
                    temp = ans;
                } else{
                    temp->next = new ListNode(b->val);
                    temp = temp->next;
                    b = b->next;
                }
        }
        return ans;
    }
};


// ALTERNATE SOLUTION

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;
        
        if (list1->val > list2->val)
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        else
        {
            list1->next = mergeTwoLists(list2, list1->next);
            return list1;
        }
    }
};
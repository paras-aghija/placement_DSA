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
    ListNode* middleNode(ListNode* head) {
        ListNode *fp, *sp;
        fp=sp=head;
        while(fp!=NULL and fp->next!=NULL){
        	fp = fp->next->next;
        	sp=sp->next;
        }
        return sp;
    }

};
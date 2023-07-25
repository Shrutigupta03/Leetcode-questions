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
        struct ListNode *p, *q, *r;
        if(!head || !head->next) return head;
        p = head;
        q = p->next;
        r = q->next;
        head->next = NULL;
        while(r){
            q->next = p;
            p = q;
            q = r;
            r = r->next;    
        }
        q->next = p;
        return q;
    }
};
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

        // if an empty list is given , return the same list
        if(!head || !head->next) return head;

        // initial positions of pointers
        p = head;
        q = p->next;
        r = q->next;

        // current head becomes last element
        // head->next needs to point to NULL
        head->next = NULL;
        
        // reversing links by traversing the list
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
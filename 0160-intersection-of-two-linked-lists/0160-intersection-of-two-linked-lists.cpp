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
         unordered_map<ListNode*,int>mp;
        ListNode *temp1=headA,*temp2=headB;
        while(temp1){
            mp[temp1]++;
            temp1=temp1->next;
        }
        temp1=headB;
        while(temp1){
            if(mp.count(temp1))
                return temp1;
            temp1=temp1->next;
        }
        return NULL;
    }
};
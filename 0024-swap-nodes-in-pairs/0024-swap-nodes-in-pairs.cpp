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
    ListNode* swapPairs(ListNode* head) {
       if(!head || !head->next) return head;
        
        ListNode* temp=head;
        
        while(temp){
            if(!temp->next) return head;
            int x = temp->val;
            temp->val = temp->next->val;
            temp->next->val = x;
            temp = temp->next->next;
        }
        return head;
    }
};
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
    void reorderList(ListNode* head) {
        
        ListNode* temp = head;
        
        if(!head || !head->next || !head->next->next) {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next->next){
            fast = fast->next;
        }
        
        ListNode* slownext = slow->next;
        
        slow->next = fast->next;
        slow->next->next = slownext;
        fast->next = NULL;
        
        reorderList(slow->next->next);
        
        return;
        
    }
};
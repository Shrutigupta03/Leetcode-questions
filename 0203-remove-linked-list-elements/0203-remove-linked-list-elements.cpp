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
    ListNode* removeElements(ListNode* head, int val) {
          while(head != NULL && head->val == val) {
            head = head->next;
        }
        if(head == NULL){
            return NULL;
        }
        
        ListNode* pointer;
        pointer = head;

        while (pointer->next != NULL)  // removing ftom middle of the linked list
        {
            if(pointer->next->val == val)
            {
                pointer->next = pointer->next->next;
            }
            else
            {
                pointer = pointer->next;    
            }
        }
        return head;
    }
};
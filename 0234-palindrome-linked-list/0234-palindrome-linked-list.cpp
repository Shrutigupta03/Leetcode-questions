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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return (head);
        }
        ListNode *dummy = NULL;
        ListNode *temp = head;
        while(temp!=NULL){
            ListNode *next = new ListNode(temp->val);
            next ->next = dummy;
            dummy = next;
            temp = temp->next;
        }
        while(head && dummy){
            if(head->val != dummy->val){
                return false;
            }
            head = head->next;
            dummy = dummy->next;
        }
        return true;
    }
};
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *start = head, *end = head;
        ListNode *prev = head, *count = head;
        int i =1;
        while(count->next){
            i++;
            count = count->next;
        }
        k = k%i;
        // cout<<i<<" "<<k<<endl;
        while(k--){
            while(end->next){
               prev = end;
               end=end->next;
            }
            prev->next = NULL;
            end->next = head;
            head = end;
        }
       return head; 
    }
};
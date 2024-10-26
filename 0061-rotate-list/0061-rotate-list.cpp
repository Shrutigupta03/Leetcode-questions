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
    
        if(!head) return head;
        
        int n = 1;
        ListNode* temp = head;
        while(temp->next){
            temp = temp->next;
            n++;
        }
        
        k = k%n;
        if(!k) return head;
        else{
            int x = n-k;
            ListNode* temp2 = head;
            while(x>1){
                temp2 = temp2->next;
                x--;
            }
            cout<<temp2->val<<endl;
            ListNode* res = temp2->next;
            temp2->next = NULL;
            temp->next = head;
            return res;
        }
    }
};
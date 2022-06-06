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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev=head;
        ListNode* fast=head;
        
        if(!head->next)
            return NULL;
        if(!head->next->next){
            head->next=NULL;
            return head;
        }
        while(fast && fast->next){
            if(fast !=head)
                prev=prev->next;
            fast=fast->next->next;
        }
        
        prev->next=prev->next->next;
        
        return head;
    }
};
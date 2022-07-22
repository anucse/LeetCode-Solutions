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
    ListNode* partition(ListNode* head, int x) {
        ListNode* frontDummy=new ListNode(0);
        ListNode* backDummy=new ListNode(0);
        ListNode* front=frontDummy ;
        ListNode* back=backDummy ;
        ListNode* curr=head;
        while(curr){
            if(curr->val<x){
                front->next=curr;
                front=front->next;
            }
            else{
                back->next=curr;
                back=back->next;
            }
            
            curr=curr->next;
        }
        
        front->next=backDummy->next;
        back->next=NULL;
        return frontDummy->next;
    }
};
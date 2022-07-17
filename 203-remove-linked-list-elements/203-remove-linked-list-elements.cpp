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
        
        
        while(head && head->val==val){
            head=head->next;
        }
        
        if(!head)
            return NULL;
        
        if(!head->next){
            if(head->val==val)
                return NULL;
            return head;
        }
        
        ListNode* one=head;
        ListNode* two=head->next;
        
        while(two){
            if(two->val==val){
                one->next=two->next;
                two=one->next;
            }
            else{
                one=one->next;
                two=two->next;
            }
        }
        
        return head;
    }
};
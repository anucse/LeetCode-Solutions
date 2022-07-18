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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *one=NULL;
        ListNode *two=head;
        ListNode *three=head->next;
        
        while(two){
            two->next=one;
            one=two;
            two=three;
            if(three)
                three=three->next;
        }
        
        return one;
        
    }
};
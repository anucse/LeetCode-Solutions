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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* one=head;
        ListNode* two=head->next;
        
        while(two){
            if(one->val==two->val){
                one->next=two->next;
                two=one->next;
            }
            else{
                one=two;
                two=two->next;
            }
        }
        return head;
    }
};
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
    ListNode* findMid(ListNode* head){
        if(!head || !head->next)
          return head;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        if(!head || !head->next)
            return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* temp=head->next;
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=temp;
            if(temp)
                temp=temp->next;
        }
        return prev;
    }
    
    bool compare(ListNode* head1,ListNode* head2){
        while(head1 && head2){
            if(head1->val != head2->val)
                return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head ||!head->next)
            return true;
        ListNode* mid=findMid(head);
        ListNode* head2=reverse(mid);
        return compare(head,head2);
    }
};
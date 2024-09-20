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
    ListNode* split(ListNode* head){
        ListNode* slow = head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        return slow;

    }

    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        if(!head || !head->next){
            return 0;
        }
        ListNode* second=split(head);
        second=reverse(second);
        ListNode* first=head;
        int ans=INT_MIN;
        while(first && second){
            ans=max(ans,first->val+second->val);
            first=first->next;
            second=second->next;
        }

        return ans;
    }
};
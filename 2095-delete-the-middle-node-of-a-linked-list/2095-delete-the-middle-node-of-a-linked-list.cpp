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
        int n=0;
        ListNode* node=head;
        while(node){
            node=node->next;
            n++;
        }
        if(n==1){
            return NULL;
        }
        if(n==2){
            head->next=NULL;
            return head;
        }
        int m=n/2;
        int p=m-1;
        //int r=m+1;
        ListNode* prev=head;
        //ListNode* right;
        while(p--){
            prev=prev->next;
        }
        ListNode* right=prev->next->next;
        prev->next=right;
        return head;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA=0,countB=0;
        ListNode* temp=headA;
        while(temp){
            temp=temp->next;
            countA++;
        }
        temp=headB;
        while(temp){
            temp=temp->next;
            countB++;
        }
        int diff=abs(countA-countB);
        while(diff--){
            if(countA>countB){
                headA=headA->next;
            }
            else{
                headB=headB->next;
            }
        }
        
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        
        return headA;
    }
};
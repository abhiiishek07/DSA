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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        while(head){
            ListNode* nxt= head->next;
            head->next=prev;
            prev=head;
            head=nxt;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head= reverse(head);
        ListNode* dummy= new ListNode(-1);
        ListNode* curr=dummy;
        int maxi=INT_MIN;
        while(head){
            maxi=max(maxi,head->val);
            if(head->val>=maxi){
                curr->next= new ListNode(head->val);
                curr=curr->next;
            }
            head=head->next;
        }
        return reverse(dummy->next);
    }
};
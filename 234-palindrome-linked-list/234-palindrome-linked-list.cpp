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
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        while(head){
            ListNode* t=head->next;
            head->next=prev;
            prev=head;
            head=t;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* mid= findMid(head);
        ListNode* head2= mid->next;
        head2 =reverse(head2);
        while(head && head2){
            if(head->val!=head2->val)
                return false;
            head=head->next;
            head2=head2->next;
        }
        return true;
    }
};
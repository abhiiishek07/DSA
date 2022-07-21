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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        int pos=1; 
       while (head && pos<left){           
           curr->next=head;
           curr=curr->next;
           head=head->next;
           pos++;
       }
        ListNode* afterRev= head;          // after reversing. 2,3,4 => 4,3,2 . afterRev=2
        ListNode* prev=NULL;
        while(head && pos<=right){
            ListNode* temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
            pos++;
        }
        curr->next=prev;
        afterRev->next=head;
        return dummy->next;
    }
};
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy= new ListNode(-1);
        ListNode* curr= dummy;
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        int t=k;
        ListNode* firstNode=head;
        while(head){
            if(n<k){                   // last condition
                curr->next=firstNode;
                break;
            }
            ListNode* prev= NULL;
            while(head && k>0){                 // reversing k nodes
                ListNode* nxt=head->next;
                head->next=prev;
                prev=head;
                head=nxt;
                k--;
            }
            k=t;            
            n-=k;                   // updating remaining nodes
            curr->next=prev;
            curr=firstNode;
            
            firstNode=head;       //it will healp in last condition 
        }
        return dummy->next;
    }
};
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
        stack<int>st;
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        int pos=1;
        while(head){
            if(pos<left){
                curr->next=new ListNode(head->val);
                curr=curr->next;
                head=head->next;
                pos++;
            }
            else if(pos>=left && pos<=right){
                st.push(head->val);
                head=head->next;
                pos++;
            }
            else
                break;
        }
        while(!st.empty()){
            curr->next=new ListNode(st.top());
            st.pop();
            curr=curr->next;
        }
        while(head){
               curr->next=head;
                curr=curr->next;
                head=head->next;
        }
        return dummy->next;
    }
};
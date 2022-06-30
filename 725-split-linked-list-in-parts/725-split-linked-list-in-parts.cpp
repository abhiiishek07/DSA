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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        int sizeOfEachPart=n/k;
        int extra=n%k;
        vector<ListNode*>ans;
        for(int i=0;i<k;i++){
            int size=sizeOfEachPart;
            if(extra>0){
                size++;
                extra--;
            }
            ListNode* dummy=new ListNode(-1);
            ListNode* curr=dummy;
            while(head && size--){
                curr->next=new ListNode(head->val);
                curr=curr->next;
                head=head->next;
            }
            ans.push_back(dummy->next);
        }
        return ans;
    }
};
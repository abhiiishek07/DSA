/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public: 
    void flat(Node* head,Node *&curr){
        if(!head)
            return;
        
        Node* temp=new Node(head->val);
        curr->next=temp;
        temp->prev=curr;
        curr->child=NULL;
        curr=curr->next;
     
        flat(head->child,curr);    
        flat(head->next,curr);
    }
    Node* flatten(Node* head) {
        if(!head)
            return NULL;
        Node* dummy=new Node(-1);
        Node* curr=dummy;
        flat(head,curr);
        Node* ans=dummy->next;
        ans->prev=NULL;              
        return ans;
    }
};
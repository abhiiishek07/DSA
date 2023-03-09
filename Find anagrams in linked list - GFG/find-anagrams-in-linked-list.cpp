//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        // code here
        int i=0,j=0,k=s.size();
        Node* start=head,*end=head;
        vector<int>sfreq(26,0),lfreq(26,0);
        for(char ch:s){
            sfreq[ch-'a']++;
        }
        vector<Node*>ans;
        while(start){
            lfreq[start->data-'a']++;
            if(j-i+1==k){
                if(sfreq==lfreq){
                    Node* next=start->next;
                    start->next=NULL;
                    ans.push_back(end);
                    start=next;
                    end=next;
                    lfreq=vector<int>(26,0);
                    j=0;
                    i=0;
                }
                else{
                    lfreq[end->data-'a']--;
                    end=end->next;
                    start=start->next;
                    i++;
                    j++;
                }
            }
            else{
                start=start->next;
                j++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends
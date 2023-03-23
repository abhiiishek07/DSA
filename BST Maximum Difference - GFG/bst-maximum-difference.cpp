//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void getMinSum(Node* node,int sum,int target,int &targetToLeafSum){
        if(!node) return;
        if(node->data!=target) sum+=node->data;
        if(!node->left && !node->right) targetToLeafSum=min(targetToLeafSum,sum);
        getMinSum(node->left,sum,target,targetToLeafSum);
        getMinSum(node->right,sum,target,targetToLeafSum);
    }
    void solve(Node* root,int target,int &rootToTargetSum,int &targetToLeafSum,int &targetFound){
        if(!root) return;
        if(root->data==target){
            getMinSum(root,0,target,targetToLeafSum);
            targetFound=1;
            return;
        }
        rootToTargetSum+=root->data;
        if(root->data>target)
        solve(root->left,target,rootToTargetSum, targetToLeafSum, targetFound);
        else
        solve(root->right,target,rootToTargetSum, targetToLeafSum, targetFound);
        
    }
    int maxDifferenceBST(Node *root,int target){
        // Code here
        int rootToTargetSum=0, targetToLeafSum=INT_MAX, targetFound=0;
        solve(root,target,rootToTargetSum, targetToLeafSum, targetFound);
        if(!targetFound) return -1;
        return rootToTargetSum-targetToLeafSum;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* solve(int &idx,int s,int e,int n,int pre[],unordered_map<int,int>&mp){
        if(s>e || idx>=n){
            return NULL;
        }
        int key= pre[idx++];
        Node* root= new Node(key);
        root->left= solve(idx,s,mp[key]-1,n,pre,mp);
        root->right= solve(idx,mp[key]+1,e,n,pre,mp);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[in[i]]=i;
        }
        int idx=0,s=0,e=n-1;
        return solve(idx,s,e,n,pre,mp);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends
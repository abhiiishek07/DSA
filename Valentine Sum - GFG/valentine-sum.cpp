//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    void getSum(Node* node, Node* prev,int d,int &res){
        if(!node || node==prev || d<0)
        return;
        
        res+= node->data;
        getSum(node->left,prev,d-1,res);
        getSum(node->right,prev,d-1,res);
    }
    bool findPath(Node* root, int t, stack<Node*>&path){
        if(!root) return false;
        
        path.push(root);
        if(root->data==t)
        return true;
        
        if(findPath(root->left,t,path) || findPath(root->right,t,path))
        return true;
        
        path.pop();
        return false;
    }
    int sum_at_distK(Node* root, int target, int k)
    {
        // Your code goes here
        stack<Node*>path;
        findPath(root,target,path);
        int ans=0;
        Node* prev=NULL;
        while(!path.empty() && k>=0){
            int res=0;
            Node* node=path.top();
            path.pop();
            getSum(node,prev,k,res);
            prev=node;
            ans+= res;
            k--;
        }
        return ans;
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        Solution obj;
        cout<< obj.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}


// } Driver Code Ends
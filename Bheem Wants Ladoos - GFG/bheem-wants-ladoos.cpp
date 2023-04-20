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
    bool getPath(Node* root, int target, stack<Node*>&path){
        if(!root) return false;
        path.push(root);
        if(root->data==target) return true;
        bool hasLeft= getPath(root->left, target, path);
        bool hasRight= getPath(root->right, target, path);
        
        if(hasLeft || hasRight) return true;
        
        path.pop();
        return false;
    }
    int getMaxLadoos(Node* node, int k, Node* prev){
        if(!node || k<0 || node==prev) return 0;
        int sum=node->data;
        sum+= getMaxLadoos(node->left,k-1,prev);
        sum+= getMaxLadoos(node->right,k-1,prev);
        return sum;
    }
    int ladoos(Node* root, int home, int k)
    {
        // Your code goes here
        stack<Node*>path;             // root to node path
        getPath(root, home, path);
        Node* prev=NULL;
        int ladoos=0;
        while(!path.empty() && k>=0){
            Node* house= path.top();
            path.pop();
            ladoos+= getMaxLadoos(house,k,prev);
            k--;
            prev=house;
        }
        return ladoos;
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
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends
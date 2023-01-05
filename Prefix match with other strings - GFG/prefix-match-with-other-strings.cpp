//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
struct Node{
    int cnt;
    vector<Node*>children;
    bool isEnd;
    Node(){
        children= vector<Node*>(26,NULL);
        cnt=0;
        isEnd=false;
    }
    bool containsKey(char ch){
        return children[ch-'a']!=NULL;
    }
    void put(char ch, Node* newNode){
        children[ch-'a']= newNode;
    }
    Node* getNext(char ch){
        return children[ch-'a'];
    }
};
class Trie{
    public: Node* root;
    Trie(){
        root= new Node();
    }
    void insert(string word){
        Node* node= root;
        for(char ch:word){
            if(!node->containsKey(ch)){
                node->put(ch, new Node());
            }
            
            node= node->getNext(ch);
            node->cnt++;
        }
        node->isEnd=true;
    }
    int allPrefix(string str){
        Node* node=root;
        for(char ch:str){
             node= node->getNext(ch);
            if(node->isEnd) break;
           
        }
        
        return node->cnt;
    }
};
class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
        Trie trie;
        for(int i=0;i<n;i++){
            trie.insert(arr[i]);
        }
        if(k>str.size()) return 0;
        str= str.substr(0,k);
        int ans= trie.allPrefix(str);
        return ans;
        
    }
    /* Accepted answer
    
    int klengthpref(string arr[], int n, int k, string str){    
      if(k>str.size()) return 0;
      str= str.substr(0,k);
      int ans=0;
      for(int i=0;i<n;i++){
          string s=arr[i];
          if(s.substr(0,k)==str)
          ans++;
      }
      return ans;
    }
    */
    
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
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
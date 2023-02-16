//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    bool dfs(int i,vector<int>&status,vector<int>&arr){
        if(i<0 || i>=arr.size())
        return 1;
        
        if(status[i]==1)
        return false;
        
        status[i]=1;
        
        bool res= dfs(i+arr[i],status,arr);
        if(res)
        status[i]=2;
        
        return res;
    }
    int goodStones(int n,vector<int> &arr){
        // Code here
        vector<int>status(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(status[i]==0)
            dfs(i,status,arr);
            
            if(status[i]==2)
            ans++;
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
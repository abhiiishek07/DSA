//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
  int solve(vector<int>&arr,int s,int e,int k,vector<vector<int>>&dp){
      if(s==e)             // only one element so min and max ele will be same
      return 0;
      
      if(arr[e]-arr[s]<=k)
      return 0;
      
      if(dp[s][e]!=-1)
      return dp[s][e];
      
      int front= 1+solve(arr,s+1,e,k,dp);
      int back= 1+solve(arr,s,e-1,k,dp);
      
      return dp[s][e]= min(front,back);
  }
    int removals(vector<int>& arr, int k){
        //Code here
        sort(arr.begin(),arr.end());
        int s=0,e=arr.size()-1;
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
        return solve(arr,s,e,k,dp);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends
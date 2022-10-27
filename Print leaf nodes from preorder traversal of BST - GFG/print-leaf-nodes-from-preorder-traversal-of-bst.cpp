//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool solve(int arr[],int &idx,int n, int mini,int maxi,vector<int>&ans){
        if(idx>=n || arr[idx]<mini || arr[idx]>maxi)
        return false;
        
        int val=arr[idx];
        idx++;
        
        bool left= solve(arr,idx,n,mini,val,ans);
        bool right= solve(arr,idx,n,val,maxi,ans);
        
        if(!left && !right){
            ans.push_back(val);
        }
        
        return true;
    }
    vector<int> leafNodes(int arr[],int N) {
        // code here
        vector<int>ans;
        int idx=0;
        bool temp= solve(arr,idx,N,INT_MIN,INT_MAX,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
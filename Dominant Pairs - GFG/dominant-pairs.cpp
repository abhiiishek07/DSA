//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int search(int s,int e,int t,vector<int>&arr){
        int cnt=0;
        int x=s;
        while(s<=e){
            int m=e+(s-e)/2;
            if(t>=(5*arr[m])){
                cnt=m-x+1;
                s=m+1;
            }
            else e=m-1;
        }
        return cnt;
    }
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        sort(arr.begin()+n/2,arr.end());
        int ans=0;
        for(int i=0;i<n/2;i++){
            ans+= search(n/2,n-1,arr[i],arr);
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
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends
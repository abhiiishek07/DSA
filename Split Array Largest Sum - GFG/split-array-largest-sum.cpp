//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(int arr[],int mid, int n,int k){
        int subArray=0,sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]>mid)
            return false;
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }
            else{
                subArray++;
                sum=arr[i];
            }
        }
        subArray++;
        return subArray<=k;
    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int totSum=0;
        for(int i=0;i<N;i++){
            totSum+=arr[i];
        }
        int low=0,high=totSum,ans;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(canSplit(arr,mid,N,K)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
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
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int N){
      //Code here.
      long long int buyer=0,seller=0,ans=0;
      while(buyer<N && seller<N){
          while(arr[buyer]<0) buyer++;
          while(arr[seller]>0)seller++;
          if(arr[buyer]>abs(arr[seller])){
              ans+= (abs(arr[seller])* (abs(seller-buyer)));
              arr[buyer]+= arr[seller];
              arr[seller]=0;
              seller++;
              
          }
          else if(arr[buyer]<abs(arr[seller])){
              ans+= (arr[buyer]*(abs(seller-buyer)));
              arr[seller]+= arr[buyer];
              arr[buyer]=0;
              buyer++;
          }
          else{
              ans+= (arr[buyer]*(abs(seller-buyer)));
              arr[buyer]=0;
              arr[seller]=0;
              seller++;
              buyer++;
          }
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
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
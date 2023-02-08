//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      vector<long long int>ans;
      long long int total=n*n,nr=0,nc=0;
      vector<int>row(n,0),col(n,0);
      for(auto task:arr){
          int r=task[0]-1,c=task[1]-1;
          if(!row[r]){
              nr++;
              row[r]=1;
              total-=(n-nc);
          }
          if(!col[c]){
              nc++;
              col[c]=1;
              total-=(n-nr);
          }
          ans.push_back(total);
      }
      return ans;
     
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends
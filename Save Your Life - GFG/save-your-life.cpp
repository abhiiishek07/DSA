//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here 
          unordered_map<char,int>mp;
          for(int i=0;i<n;i++){
              mp[x[i]]=b[i];
          }
          int sum=0,maxi=INT_MIN;
          int end=0;
          for(int i=0;i<w.size();i++){
              char ch=w[i];
              int val;
              if(mp.find(ch)!=mp.end()){
                  val= mp[ch];
              }
              else{
                  val= ch;
              }
              sum+= val;
              if(sum<val){
                  sum=val;
              }
              if(sum>=maxi){
                  maxi=sum;
                  end=i;
              }
          }
          int start=end;
          while(start>=0){
              char ch=w[start];
              int val;
              if(mp.find(ch)!=mp.end())
              val=mp[ch];
              else
              val= w[start];
              maxi-= val;
              if(maxi==0)
              break;
              
              start--;
          }
          string ans= w.substr(start, end-start+1);
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
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int solve(int n,vector<int>&dp){
        if(n==1 || n==2)
          return n;
        if(dp[n]!=-1)
          return dp[n];
          
        long  pair= solve(n-2,dp);
        long not_pair= solve(n-1,dp);
        
        return dp[n]=((n-1)*pair+not_pair)%1000000007;
    }
    int countFriendsPairings(int n) 
    { 
        // code here
        vector<int>dp(10001,-1);
        return solve(n,dp);
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends
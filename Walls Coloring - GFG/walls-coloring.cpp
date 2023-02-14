//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int solve(int i,int j,vector<vector<int>>&colors,vector<vector<int>>&dp){
        if(i==0) return colors[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int op1= colors[i][j]+solve(i-1,(j+1)%3,colors,dp);
        int op2= colors[i][j]+solve(i-1,(j+2)%3,colors,dp);
        return dp[i][j]=min(op1,op2);
        // return min(op1,op2);
    }
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        vector<vector<int>>dp(N,vector<int>(3,INT_MAX));
        int ans=INT_MAX;
        for(int j=N-1;j>=0;j--){
            solve(N-1,j,colors,dp);
        }
        return min({dp[N-1][0],dp[N-1][1],dp[N-1][2]});
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends
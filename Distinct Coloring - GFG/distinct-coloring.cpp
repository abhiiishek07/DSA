//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int solve(int i,int j,vector<vector<long long int>>&colors,vector<vector<long long int>>&dp){
        if(j==0) return colors[i][0];
        if(dp[i][j]!=-1) return dp[i][j];
        long long int op1= colors[i][j]+solve((i+1)%3,j-1,colors,dp);
        long long int op2= colors[i][j]+solve((i+2)%3,j-1,colors,dp);
        return dp[i][j]=min(op1,op2);
        
    }
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here
        vector<vector<long long int>>colors(3);
        colors[0]=vector<long long int>(r,r+N);
        colors[1]=vector<long long int>(g,g+N);
        colors[2]=vector<long long int>(b,b+N);
        vector<vector<long long int>>dp(3,vector<long long int>(N+1,-1));
        for(int i=0;i<3;i++){
            long long int cost=solve(i,N-1,colors,dp);
        }
        return min({dp[0][N-1],dp[1][N-1],dp[2][N-1]});
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
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends
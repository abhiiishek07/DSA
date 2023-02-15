//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    vector<vector<int>>dirs={{0,1},{1,0},{-1,0},{0,-1}};
    bool isPossible(int x,int y,vector<vector<int>>&vis,vector<vector<int>>&mat,int curVal){
        if(x<0 || y<0 || x>=mat.size() || y>=mat[0].size() || vis[x][y] || curVal>mat[x][y])
        return false;
        
        return true;
    }
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&mat){
        vis[i][j]=1;
        int curVal=mat[i][j];
        for(auto dir:dirs){
            int x=i+dir[0], y=j+dir[1];
            if(isPossible(x,y,vis,mat,curVal))
            dfs(x,y,vis,mat);
        }
    }
    int water_flow(vector<vector<int>> &mat,int N,int M){
    // Write your code here.
    vector<vector<int>>canReachArabian(N,vector<int>(M,0));
    vector<vector<int>>canReachIndian(N,vector<int>(M,0));
    
    for(int i=0;i<N;i++) dfs(i,0,canReachArabian,mat);
    for(int i=0;i<M;i++) dfs(0,i,canReachArabian,mat);
    for(int i=0;i<N;i++) dfs(i,M-1,canReachIndian,mat);
    for(int i=0;i<M;i++) dfs(N-1,i,canReachIndian,mat);
    
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(canReachArabian[i][j] && canReachIndian[i][j])
            cnt++;
        }
    }
    return cnt;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends
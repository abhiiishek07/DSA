//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool isValid(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m) return false;
        return true;
    }
    int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
        // Code here
        int n=arr.size(), m=arr[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({start_x,start_y});
        vis[start_x][start_y]=1;
        
        vector<int>dx={-2,-1,1,2,2,1,-1,-2};
        vector<int>dy={1,2,2,1,-1,-2,-2,-1};
        
        vector<int>scores;
        while(!q.empty()){
            int sz=q.size();
            int score=0;
            while(sz--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                score+= arr[x][y];
                for(int i=0;i<8;i++){
                    int new_x=x+dx[i];
                    int new_y=y+dy[i];
                    if(isValid(new_x,new_y,n,m) && !vis[new_x][new_y]){
                        q.push({new_x,new_y});
                        vis[new_x][new_y]=1;
                    }
                }
            }
            scores.push_back(score);
        }
        int maxi=INT_MIN,idx;
        for(int i=scores.size()-1;i>=0;i--){
            if(i+scores[i]<scores.size())
            scores[i]=scores[i]+scores[scores[i]+i];
            
            if(scores[i]>=maxi){
                maxi=scores[i];
                idx=i;
            }
        }
        return idx;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        queue<pair<int,int>>q;
        q.push({x-1,y-1});
        vector<vector<int>>vis(N,vector<int>(M,0));
        vis[x-1][y-1]=1;
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int i=q.front().first,j=q.front().second;
                q.pop();
                if(i-1>=0 && !vis[i-1][j]){
                    q.push({i-1,j});
                    vis[i-1][j]=1;
                }
                if(i+1<N && !vis[i+1][j]){
                    q.push({i+1,j});
                    vis[i+1][j]=1;
                }
                if(j-1>=0 && !vis[i][j-1]){
                    q.push({i,j-1});
                    vis[i][j-1]=1;
                }
                if(j+1<M && !vis[i][j+1]){
                    q.push({i,j+1});
                    vis[i][j+1]=1;
                }
            }
            ans++;
        }
        return ans==0 ? 0 : ans-1;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
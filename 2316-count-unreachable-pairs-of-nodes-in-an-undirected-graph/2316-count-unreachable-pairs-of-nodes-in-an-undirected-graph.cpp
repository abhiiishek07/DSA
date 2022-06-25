class Solution {
public:
    long long getComp(int idx,vector<int>&vis,vector<vector<int>>&adj){
        if(vis[idx])
            return 0;
        vis[idx]=1;
        long long c=1;
        for(auto it:adj[idx]){
            if(!vis[it]){
                c+= getComp(it,vis,adj);
            }
        }
        return c;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(int i=0;i<edges.size();i++){
            int u= edges[i][0];
            int v= edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long count=0,ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                long long x= getComp(i,vis,adj);
                ans+= count*x;
                count+= x;
            }
        }
        return ans; 
    }
};
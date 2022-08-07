class Solution {
public:
    int ans=0;
    void dfs(int src,vector<vector<int>>&adj,vector<int>&vis){
        vis[src]=1;
        ans++;
        for(int v:adj[src]){
            if(!vis[v])
                dfs(v,adj,vis);
        }
        return;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>>adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n+1,0);
        for(int x:restricted)
            vis[x]=1;
        dfs(0,adj,vis);
        return ans;
    }
};
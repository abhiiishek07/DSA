class Solution {
public:
    int ans=0;
    void dfs(int src,vector<vector<int>>&adj,vector<int>&vis,unordered_set<int>&st){
        vis[src]=1;
        ans++;
        for(int v:adj[src]){
            if(st.find(v)==st.end() && !vis[v])
                dfs(v,adj,vis,st);
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
        unordered_set<int>st(restricted.begin(),restricted.end());
        dfs(0,adj,vis,st);
        return ans;
    }
};
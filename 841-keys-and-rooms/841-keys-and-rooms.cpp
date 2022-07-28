class Solution {
public:
    void solve(int s,vector<vector<int>>adj,vector<int>&vis){
        vis[s]=1;
        for(int v:adj[s]){
            if(!vis[v])
                solve(v,adj,vis);
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
       for(int i=0;i<n;i++){
           for(int j=0;j<rooms[i].size();j++){
               adj[i].push_back(rooms[i][j]);
           }
       }
        solve(0,adj,vis);
        for(int x:vis){
            if(!x)
                return false;
        }
        return true;
    }
};
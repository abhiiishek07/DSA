class Solution {
public:
    void solve(int s,vector<vector<int>>& rooms,vector<int>&vis){
        vis[s]=1;
        for(int v:rooms[s]){
            if(!vis[v])
                solve(v,rooms,vis);
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,0);
        solve(0,rooms,vis);
        for(int x:vis){
            if(!x)
                return false;
        }
        return true;
    }
};
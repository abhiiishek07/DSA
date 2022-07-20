class Solution {
public:
    void solve(int firstEle,unordered_map<int,vector<int>>&adj,unordered_set<int>&visited,vector<int>&ans){
        ans.push_back(firstEle);
        visited.insert(firstEle);
        for(int x:adj[firstEle]){
            if(visited.find(x)==visited.end())
                solve(x,adj,visited,ans);
        }
        return;
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>adj;
        for(auto it:adjacentPairs){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int firstEle;
        for(auto it:adj){
            if(it.second.size()==1){
                firstEle=it.first;
                break;
            }
        }
        unordered_set<int>visited;
        vector<int>ans;
        solve(firstEle,adj,visited,ans);
        return ans;
    }
};
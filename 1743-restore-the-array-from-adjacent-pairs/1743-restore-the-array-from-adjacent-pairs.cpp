class Solution {
public:
    void solve(int firstEle,unordered_map<int,vector<int>>&adj,unordered_map<int,int>&visited,vector<int>&ans){
        ans.push_back(firstEle);
        visited[firstEle]++;
        for(int x:adj[firstEle]){
            if(visited.find(x)==visited.end())
                solve(x,adj,visited,ans);
        }
        return;
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
       unordered_map<int,int>mp;
        for(auto it:adjacentPairs){
            mp[it[0]]++;
            mp[it[1]]++;
        }
        int firstEle;
        for(auto it:mp){
            if(it.second==1){
                firstEle=it.first;
                break;
          }
        }
        unordered_map<int,vector<int>>adj;
        for(auto it:adjacentPairs){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        unordered_map<int,int>visited;
        vector<int>ans;
        solve(firstEle,adj,visited,ans);
        return ans;
        
    }
};
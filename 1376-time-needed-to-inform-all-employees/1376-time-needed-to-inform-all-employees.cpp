class Solution {
public:
    int dfs(int head,unordered_map<int,vector<int>>&mp,vector<int>& informTime){
        if(informTime[head]==0)
            return 0;
        int time=0,ans=INT_MIN;
        for(auto it:mp[head]){
            time=informTime[head]+ dfs(it,mp,informTime);
            ans=max(ans,time);
        }
        return ans;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            if(i!=headID)
                mp[manager[i]].push_back(i);
        }
       return dfs(headID,mp,informTime);
       
    }
};
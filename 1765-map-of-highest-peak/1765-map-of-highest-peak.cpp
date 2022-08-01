class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        vector<vector<int>>vis(m+1,vector<int>(n+1,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int size=q.size();
            while(size--){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            if(i-1>=0 && !vis[i-1][j]){
                ans[i-1][j]=dis+1;
                q.push({{i-1,j},dis+1});
                vis[i-1][j]=1;
            }
            if(j+1<n && !vis[i][j+1]){
                ans[i][j+1]=dis+1;
                q.push({{i,j+1},dis+1});
               vis[i][j+1]=1;
            }
            if(i+1<m && !vis[i+1][j]){
                ans[i+1][j]=dis+1;
                q.push({{i+1,j},dis+1});
                vis[i+1][j]=1;
            }
            if(j-1>=0 && !vis[i][j-1]){
                ans[i][j-1]=dis+1;
                q.push({{i,j-1},dis+1});
               vis[i][j-1]=1;
            }   
        }
        }
        return ans;
    }
};
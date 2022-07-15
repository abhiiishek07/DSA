class Solution {
public:
    void solve(int i,int j,int &cnt, vector<vector<int>>&grid){
        if(i>=grid.size() || j>=grid[0].size() || !grid[i][j])
            return;
        cnt++;
        grid[i][j]=0;
        solve(i+1,j,cnt,grid);
        solve(i,j+1,cnt,grid);
        solve(i-1,j,cnt,grid);
        solve(i,j-1,cnt,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    int cnt=0;
                    solve(i,j,cnt,grid);
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int solve(int i1,int j1,int i2,int j2,vector<vector<int>>&grid,vector<vector<vector<vector<int>>>>&dp){
        if(i1<0 || j1<0 || i2<0 || j2<0 || grid[i1][j1]==-1 || grid[i2][j2]==-1)
            return -1e8;
        
        if(i1==0 && j1==0)
            return grid[i1][j1];
        
        if(dp[i1][j1][i2][j2]!=-1)
            return dp[i1][j1][i2][j2];
        
        int val= grid[i1][j1];
        if(i1!=i2)
            val+= grid[i2][j2];
        
        int ll= solve(i1,j1-1,i2,j2-1,grid,dp);
        int lu= solve(i1,j1-1,i2-1,j2,grid,dp);
        int uu= solve(i1-1,j1,i2-1,j2,grid,dp);
        int ul= solve(i1-1,j1,i2,j2-1,grid,dp);
        
        return dp[i1][j1][i2][j2]= val +max({ll,lu,uu,ul});
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>> (n, vector<int>(n, -1))));
        int ans= solve(n-1,n-1,n-1,n-1,grid,dp);
        return ans<=0 ? 0: ans;
    }
};
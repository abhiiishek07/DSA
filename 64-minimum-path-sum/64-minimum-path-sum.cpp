class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                     dp[0][0]=grid[0][0];
                }
                else{
                  int up= i>0 ? dp[i-1][j]:INT_MAX;
                  int left= j>0 ? dp[i][j-1]:INT_MAX;
                 dp[i][j]= grid[i][j] + min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

 /*
  MEMO
  
  int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i==0 && j==0)
            return grid[0][0];
        if(i<0||j<0)
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up=solve(i-1,j,grid,dp);
        int left=solve(i,j-1,grid,dp);
        return dp[i][j]= grid[i][j]+min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
    }
    */
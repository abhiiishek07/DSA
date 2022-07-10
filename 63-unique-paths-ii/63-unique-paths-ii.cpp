class Solution {
public:
      int solve(int m,int n,vector<vector<int>>&dp,vector<vector<int>>& og){
        if(m<0 || n<0)
            return 0;
           if(og[m][n])
              return 0;
        if(m==0 && n==0)
            return 1;
        if(dp[m][n]!=-1)
            return dp[m][n];
        return dp[m][n]=solve(m-1,n,dp,og)+solve(m,n-1,dp,og);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
         vector<vector<int>>dp(m,(vector<int>(n,-1)));
        return solve(m-1,n-1,dp,obstacleGrid);
    }
};
  
class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
         if(j<0||j>=matrix.size())
            return INT_MAX; 
        if(i==0){
            return matrix[i][j];
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int digLeft=solve(i-1,j-1,matrix,dp);
        int up=solve(i-1,j,matrix,dp);
        int digRight=solve(i-1,j+1,matrix,dp);
        dp[i][j]=matrix[i][j]+min({digLeft,up,digRight});
        return dp[i][j];     
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int res=INT_MAX;
        for(int j=0;j<n;j++)
            res=min(res,solve(n-1,j,matrix,dp));
        return res;
    }
};
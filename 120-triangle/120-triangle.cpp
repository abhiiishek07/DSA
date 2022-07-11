class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
        if(i==triangle.size()-1)
            return triangle[i][j];
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
            int sum= triangle[i][j]+ min(solve(i+1,j,triangle,dp),solve(i+1,j+1,triangle,dp));
            return dp[i][j]=sum;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(201,vector<int>(201,-1));
        return solve(0,0,triangle,dp);
    }
};
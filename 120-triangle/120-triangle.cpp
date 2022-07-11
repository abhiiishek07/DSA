class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(201,vector<int>(201,-1));
        int m=triangle.size();
        for(int j=0;j<triangle[m-1].size();j++){
            dp[m-1][j]= triangle[m-1][j];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                dp[i][j]=triangle[i][j]+ min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};

/*
   MEMO (accepted)
    
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
    */
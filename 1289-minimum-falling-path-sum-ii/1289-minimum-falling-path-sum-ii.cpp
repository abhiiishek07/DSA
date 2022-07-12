class Solution {
public:
    int solve(int i,int prev,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i==0){
            int mini=INT_MAX;
            for(int c=0;c<grid[0].size();c++){
                if(c!=prev)
                    mini=min(mini,grid[0][c]);
            }
            return mini; 
        }
        if(dp[i][prev]!=-1)
            return dp[i][prev];
        int mini=INT_MAX;
        for(int c=0;c<grid[i].size();c++){
            if(c!=prev){
                int sum= grid[i][c]+ solve(i-1,c,grid,dp);
                mini=min(mini,sum);
            }
        }
        return dp[i][prev]=mini;
        
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1)
            return grid[0][0];
        vector<vector<int>>dp(n,vector<int>(201,-1));
        int res=INT_MAX;
        for(int lastRow=0;lastRow<n;lastRow++){
            int potAns= solve(n-1,lastRow,grid,dp);
            res=min(res,potAns);
        }
        return res;
    }
};
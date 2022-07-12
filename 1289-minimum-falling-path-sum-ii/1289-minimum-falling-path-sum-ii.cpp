class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>last(n,0);
        for(int i=0;i<n;i++)
            last[i]=grid[0][i];
        
        for(int i=1;i<n;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                int prev=j,mini=INT_MAX;
                for(int k=0;k<n;k++)
                   if(k!=prev){
                    int sum= grid[i][prev]+last[k];
                       mini=min(mini,sum);
                }
                 curr[j]=mini; 
            }
            last=curr;
        }
         int res=INT_MAX;
        for(int lastRow=0;lastRow<n;lastRow++){
            int potAns= last[lastRow];
            res=min(res,potAns);
        }
        return res;
        
    }
};

/*  TABULATION (accepted :) )

       int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
            dp[0][i]=grid[0][i];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int prev=j,mini=INT_MAX;
                for(int k=0;k<n;k++)
                   if(k!=prev){
                    int sum= grid[i][prev]+dp[i-1][k];
                    mini=min(mini,sum);
                }
                dp[i][prev]=mini;
            }
        }
         int res=INT_MAX;
        for(int lastRow=0;lastRow<n;lastRow++){
            int potAns= dp[n-1][lastRow];
            res=min(res,potAns);
        }
        return res;
    }
    
           *********************

MEMO (accepted but very high run time)

        int solve(int i,int prev,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i==0){
            return grid[i][prev];
        }
        if(dp[i][prev]!=-1)
            return dp[i][prev];
        int mini=INT_MAX;
        for(int c=0;c<grid.size();c++){
            if(c!=prev){
                int sum= grid[i][prev]+ solve(i-1,c,grid,dp);
                mini=min(mini,sum);
            }
        }
        return dp[i][prev]=mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int res=INT_MAX;
        for(int lastRow=0;lastRow<n;lastRow++){
            int potAns= solve(n-1,lastRow,grid,dp);
            res=min(res,potAns);
        }
        return res;
    }
*/
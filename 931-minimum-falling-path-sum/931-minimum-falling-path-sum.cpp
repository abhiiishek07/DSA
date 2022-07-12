class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
            dp[0][i]=matrix[0][i];
        
            for(int i=1;i<n;i++){
                for(int j=0;j<n;j++){
                    int dl,u,dr;
                   dl= j-1>=0? dp[i-1][j-1]:INT_MAX;
                    u=dp[i-1][j];
                   dr= j+1<n ? dp[i-1][j+1]:INT_MAX;
                    dp[i][j]=matrix[i][j]+ min({dl,u,dr});
                }
            }
       int res=INT_MAX;
        for(int j=0;j<n;j++)
            res=min(res,dp[n-1][j]);
        return res;
    }
};

/* MEMO (accepted)

  int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
         if(j<0||j>=matrix.size())
            return INT_MAX; 
        if(i==0){
            return matrix[i][j];
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int digLeft=solve(i-1,j-1,matrix,dp);    // diagonal left
        int up=solve(i-1,j,matrix,dp);           // up
        int digRight=solve(i-1,j+1,matrix,dp);   // diagonal Right
        
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
*/
class Solution {
public:
    long long solve(int m,int n,int mx,int i,int j,vector<vector<vector<long long>>>&dp){ 
         if(i<0||j<0||i>=m||j>=n)
            return 1;
        if(mx==0)
            return 0;
        if(dp[i][j][mx]!=-1)
            return dp[i][j][mx];
        long long u=0,d=0,l=0,r=0;
        u+= solve(m,n,mx-1,i-1,j,dp);
        d+= solve(m,n,mx-1,i+1,j,dp);
        l+= solve(m,n,mx-1,i,j-1,dp);
        r+= solve(m,n,mx-1,i,j+1,dp);
        return dp[i][j][mx]= (u+d+l+r)%1000000007;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long long>>>dp(m+1,vector<vector<long long>>(n+1,vector<long long>(maxMove+1,-1)));
        return solve(m,n,maxMove,startRow,startColumn,dp);
    }
};
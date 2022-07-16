class Solution {
public:
    int totAlice(int i,int j,vector<int>& piles,vector<vector<int>>&dp){
        if(j<0 || i>=piles.size())
            return 0;
        if(i==j)
            return piles[i];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int op1=piles[i]+max(totAlice(i+2,j,piles,dp),totAlice(i+1,j-1,piles,dp));
        int op2=piles[j]+max(totAlice(i+1,j-1,piles,dp),totAlice(i,j-2,piles,dp));
        return dp[i][j]=max(op1,op2);
    }
    bool stoneGame(vector<int>& piles) {
        int totSum= accumulate(piles.begin(),piles.end(),0);
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int alice= totAlice(0,n-1,piles,dp);
        int bob=totSum-alice;
        return alice>=bob;
    }
};
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,INT_MAX);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            int two= cost[i]+dp[i-2];
            int one= cost[i]+dp[i-1];
            dp[i]=min(two,one);
        }
        return min(dp[n-1],dp[n-2]);
    }
};
/*
int solve(int n,vector<int>& cost,vector<int>&dp){
        if(n<=1)
            return cost[n];
        
        if(dp[n]!=-1)
            return dp[n];
        
        int two= cost[n]+solve(n-2,cost,dp);
        int one= cost[n]+solve(n-1,cost,dp);
         
        return dp[n]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(solve(n-1,cost,dp),solve(n-2,cost,dp));
        
    }
    */
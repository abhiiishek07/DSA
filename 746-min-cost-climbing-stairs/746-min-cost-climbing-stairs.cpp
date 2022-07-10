class Solution {
public:
    int solve(int n,vector<int>& cost,vector<int>&dp){
        if(n<=1)
            return cost[n];
        if(n<0) return 0;
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
};
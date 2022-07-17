class Solution {
public:
    int solve(int col,int lane,vector<int>&obstacles,vector<vector<int>>&dp){
        if(col==obstacles.size()-1)
            return 0;
        if(dp[col][lane]!=-1)
            return dp[col][lane];
        if(obstacles[col+1]!=lane+1)
            return dp[col][lane]= solve(col+1,lane,obstacles,dp);
        else{
            int sideWays=INT_MAX;
            for(int i=0;i<3;i++){
                int temp=INT_MAX;
                if(i!=lane && obstacles[col]!=i+1)
                    temp=1+ solve(col,i,obstacles,dp);
                sideWays=min(sideWays,temp);
            }
            return dp[col][lane]=sideWays;
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return solve(0,1,obstacles,dp);
    }
};
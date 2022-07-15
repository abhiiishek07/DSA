class Solution {
public:
    bool solve(int idx,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target==0)
            return true;
        if(idx==0){
            return nums[0]==target;
        }
        if(dp[idx][target]!=-1)
            return dp[idx][target];
        bool not_pick= solve(idx-1,target,nums,dp);
        bool pick=false;
        if(nums[idx]<=target)
            pick= solve(idx-1,target-nums[idx],nums,dp);
        return dp[idx][target]= pick || not_pick;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum= accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)
            return false;
        vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
        return solve(n-1,sum/2,nums,dp);
    }
};
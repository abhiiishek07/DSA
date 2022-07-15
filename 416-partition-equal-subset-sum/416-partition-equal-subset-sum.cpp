class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum= accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)
            return false;
        vector<vector<bool>>dp(n,vector<bool>((sum/2)+1,false));
        for(int i=0;i<n;i++)
            dp[i][0]=true;
        if(nums[0]<sum/2)
          dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum/2;target++){
                bool not_pick= dp[i-1][target];
                bool pick=false;
                if(nums[i]<=target)
                   pick= dp[i-1][target-nums[i]];
            dp[i][target]= pick | not_pick;
            }
        }
        return dp[n-1][sum/2];
    }
};
/* MEMO (accepted)

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
    */
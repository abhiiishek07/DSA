class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int dp[n];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
            int pick= nums[i]+dp[i-2];
            int not_pick= 0+dp[i-1];
            dp[i]=max(pick,not_pick);
        }
        return dp[n-1];
    }
};

/* Recursion (will give TLE). TC- 2^n, sc: O(n)
   
   int solve(int idx,vector<int>nums){
        if(idx==0)                //base case
            return nums[0];
        if(idx<0)
            return 0;
        int pick= nums[idx]+solve(idx-2,nums);
        int not_pick= 0+solve(idx-1,nums);
        
        return max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        return solve(n-1,nums);
    }
           ****************
    MEMOIZATION (accepted). TC: O(n), sc: O(n)+O(n)
    
     int solve(int idx,vector<int>nums,vector<int>&dp){
        if(idx==0)
            return nums[0];        //base case
        if(idx<0)
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int pick= nums[idx]+solve(idx-2,nums,dp);
        int not_pick= 0+solve(idx-1,nums,dp);
        
        return dp[idx]= max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,nums,dp);
    }
          ****************
    */
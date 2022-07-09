class Solution {
public:
    long long f(vector<int>& nums,int ind,int n,vector<int>& dp){
        if(ind>=n-1) return 0;
        if(dp[ind]!=-1) return dp[ind];

        long long minjump = INT_MAX;
        for(int k = nums[ind]+ind;k>=1+ind;k--){
            long long jump = 1 + f(nums,k,n,dp);
            minjump = min(minjump,jump);
        }
        return dp[ind] = minjump;
    }    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return f(nums,0,n,dp);
    }
};
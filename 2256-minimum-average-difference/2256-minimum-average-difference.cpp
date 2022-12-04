class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        long long int mini=INT_MAX,preSum=0,ans=0,totSum=0;
        for(int num:nums){
            totSum+=num;
        }
        for(int i=0;i<n;i++){
            preSum+= nums[i];
            totSum-= nums[i];
            long long int left=0,right=0;
            left= preSum/(i+1);
            if(i==n-1) right=0;
            else right= totSum/(n-i-1);
            long long int diff= abs(left-right);
            if(diff<mini){
                ans=i;
                mini=diff;
            }
        }
        return (int)ans;
    }
};
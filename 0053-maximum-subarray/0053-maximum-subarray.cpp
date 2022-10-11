class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<nums[i])
                sum=nums[i];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};
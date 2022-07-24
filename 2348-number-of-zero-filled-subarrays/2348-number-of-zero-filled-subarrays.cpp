class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int i=-1,j=0;
        while(j<nums.size()){
            if(nums[j]==0)
                ans+= j-i;
            else
                i=j;
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            bool c1= nums[i]+nums[i+1]>nums[i+2]?1:0;
            bool c2= nums[i]+nums[i+2]>nums[i+1]?1:0;
            bool c3= nums[i+1]+nums[i+2]>nums[i]?1:0;
            if(c1 && c2 && c3){
                int peri=nums[i]+nums[i+1]+nums[i+2];
                ans=max(ans,peri);
            }
        }
        return ans;
    }
};
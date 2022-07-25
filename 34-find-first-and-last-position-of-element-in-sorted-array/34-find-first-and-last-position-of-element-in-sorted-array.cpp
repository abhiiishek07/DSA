class Solution {
public:
    int solve(vector<int>&nums,int t,bool isFirst){
        int l=0,h=nums.size()-1,ans=-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(nums[m]==t){
                ans=m;
                if(isFirst)
                    h=m-1;
                else
                    l=m+1;
            }
            else if(nums[m]>t)
                h=m-1;
            else
                l=m+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int f= solve(nums,target,true);
        if(f==-1)
            return {-1,-1};
        int l=solve(nums,target,false);
        return  {f,l};
    }
};
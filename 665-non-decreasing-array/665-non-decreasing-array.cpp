class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0,n=nums.size();
        if(n==1)
            return true;
        
        if(nums[0]>nums[1]){
            nums[0]=nums[1];
            cnt++;
        }
        for(int i=1;i<n-2;i++){
            if(nums[i]>=nums[i-1] && nums[i]<=nums[i+1])
                continue;
            else{
                if(nums[i-1]<=nums[i+1]){
                    nums[i]=nums[i+1];
                    cnt++;
                }
                else if(nums[i]<=nums[i+2]){
                    nums[i+1]=nums[i];
                    cnt++;
                }
                else
                    return false;
            }
            if(cnt>1)
                return false;
        }
        if(nums[n-2]>nums[n-1])
            cnt++;
        return cnt<=1 ? true:false;
    }
};
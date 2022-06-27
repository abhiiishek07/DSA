class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int countZero=0,i=0,j=0,ans=0;
        while(j<nums.size()){
            if(nums[j]==0)
                countZero++;
            while(countZero>1){
                if(nums[i]==0)
                    countZero--;
                i++;
            }
            ans=max(ans,j-i);
            j++;
        }
        return ans;
    }
};
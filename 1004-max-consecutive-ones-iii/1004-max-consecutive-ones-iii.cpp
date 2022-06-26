class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int countZero=0,ans=0,i=0,j=0;
        while(j<nums.size()){
            if(nums[j]==0)
                countZero++;
            while(countZero>k){
                if(nums[i]==0)
                    countZero--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
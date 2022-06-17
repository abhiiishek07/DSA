class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,cnt=0;
        for(int x:nums){
          if(x==1)
              ans=max(ans,++cnt);
            else
              cnt=0;
        }
        return ans;
    }
};
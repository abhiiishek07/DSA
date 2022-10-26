class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            sum+=x;
            int r=sum%k;
            if(r==0 && i>0)
                return true;
            if(mp.find(r)!=mp.end()){
                if(i-mp[r]>=2)
                    return true;
            }
            else
                mp[r]=i;

        }
        return false;
    }
};
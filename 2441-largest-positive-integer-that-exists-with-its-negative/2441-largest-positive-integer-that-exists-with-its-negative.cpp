class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans=-1;
        unordered_map<int,int>mp;
        for(int x:nums){
           if(mp.find(-x)!=mp.end())
               ans=max(ans,abs(x));
            mp[x]++;
        }
        return ans;
    }
};
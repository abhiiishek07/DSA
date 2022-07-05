class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<long long,long long>mp;
        for(int x:nums)
            mp[x]++;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]-1)==mp.end()){
                long long x=nums[i];
                int cnt=0;
                while(mp.find(x)!=mp.end()){
                    cnt++;
                    x++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans=0;
        unordered_map<long,long>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]-i)==mp.end()){
                ans+=i;
            }
            else{
                ans+=i;
                ans-=mp[nums[i]-i];
            }
            mp[nums[i]-i]++;
        }
        return ans;
    }
};
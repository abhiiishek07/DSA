class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>mp;
        int i=0,j=0,sum=0;
        while(j<nums.size()){
            mp[nums[j]]++;
            sum+= nums[j];
            if(j-i+1==mp.size()){
                ans=max(ans,sum);
            }
            else if(mp.size()<j-i+1){
                while(mp.size()<j-i+1){
                    sum-= nums[i];
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)
                        mp.erase(nums[i]);
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};
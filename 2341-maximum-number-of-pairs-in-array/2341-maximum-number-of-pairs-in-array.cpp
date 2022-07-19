class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x:nums)
            mp[x]++;
        int pairs=0,cnt=0;
        for(auto it:mp){
            pairs+= it.second/2;
            if(it.second%2!=0)
                cnt++;
        }
        return {pairs,cnt};
    }
};
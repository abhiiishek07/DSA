class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        long long ans=0;
        for(int x:nums){
            string num= to_string(x);
            reverse(num.begin(),num.end());
            int revX= stoi(num);
            int diff=x-revX;
            if(mp.find(diff)!=mp.end())
                ans+= mp[diff];
            mp[diff]++;
        }
        return ans%1000000007;
    }
};
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<long long,long long>mp;
        for(int x:tasks)
            mp[x]++;
        int ans=0;
        for(auto it:mp){
            if(it.second<=1)
                return -1;
            else{
                if(it.second%3==0)
                    ans+= it.second/3;
                else
                    ans+= it.second/3+1;
            }
        }
        return ans;
    }
};
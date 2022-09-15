class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2)
            return {};
        sort(changed.begin(),changed.end());
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int x:changed)
            mp[x]++;
        for(int x:changed){
            if(mp[x]==0)
                continue;
            if(mp.find(x*2)!=mp.end()){
                ans.push_back(x);
                mp[x]--;
                if(mp[x]==0)
                    mp.erase(x);
                mp[x*2]--;
                if(mp[x*2]==0)
                    mp.erase(x*2);
            }
            else
                return {};
        }
        return ans;
    }
};
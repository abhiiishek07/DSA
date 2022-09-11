class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int>mp;
        int ans=0;
        for(char ch:s){
            if(mp.find(ch)!=mp.end()){
                ans++;
                mp.clear();
                mp[ch]++;
            }
            else
                mp[ch]++;
        }
        ans++;
        return ans;
    }
};
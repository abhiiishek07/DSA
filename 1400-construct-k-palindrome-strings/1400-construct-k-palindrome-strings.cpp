class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k)
            return false;
        unordered_map<char,int>mp;
        for(char ch:s)
            mp[ch]++;
        int odd=0;       // number of odd characters
        for(auto it:mp){
            if(it.second%2)
                odd++;
        }
        return odd<=k;
    }
};
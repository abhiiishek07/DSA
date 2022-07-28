class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        for(char ch:t){
            if(mp.find(ch)==mp.end())
                return false;
            mp[ch]--;
            if(mp[ch]==0)
                mp.erase(ch);
        }
        return mp.size()==0;
    }
};
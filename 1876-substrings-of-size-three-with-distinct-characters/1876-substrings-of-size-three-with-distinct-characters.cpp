class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char,int>mp;
        int cnt=0,i=0,j=0;
        while(j<s.length()){
            mp[s[j]]++;
            if(j-i+1==3){
                if(mp.size()==3)
                    cnt++;
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
            j++;
        }
        return cnt;
    }
};